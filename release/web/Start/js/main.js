let listNode = [];
let cppObj;

window.onload = () => {
	//初始化QT
	new QWebChannel(qt.webChannelTransport, function(channel) {
		cppObj = channel.objects.cppObj;
		cppObj.event_onLoad(); //初始化Cpp
	});
	
	// addProjectNode("img/favicon.ico","测试","测试123");
	// showProjectList();
	
	addNews("img/news.jpeg","https://www.baidu.com","火猴全新平台即将开发完成","据记者了解到，火猴系列开发工具将迎来全新版本。根据内部人员透露，火猴的新平台将会以“火猴2023”来命名，这将是一个全新的跨平台的IDE");
}


//设置公告信息
function setTips(msg) {
	if (msg == "") {
		msg = "无内容";
	}
	document.getElementById("MessageText").innerHTML = msg;
}

//清理单个列表项目
function closeSign(type) {
	let obj = document.querySelectorAll("#projectList li");
	let parent = document.getElementById('projectList');
	for (val of obj) {
		if (val.getAttribute('sign') == type) {
			parent.removeChild(val);
			cppObj.event_onCloseSign(type); //调用Cpp的清理
		}
	}

	for (var a = listNode - 1; a >= 0; a--) { //删除本地记录
		if (listNode[a].path == type) {
			listNode.splice(a);
		}
	}
	
	//如果是全部删除
	if (document.querySelectorAll("#projectList li").length == 0) {
		closeAllSign();
	}
}

//删除全部项目
function closeAllSign() {
	document.getElementById("projectList").innerHTML = "";
	document.getElementById("projectTip").style.display = "block";
	document.getElementById("clearList").style.display = "none";
	cppObj.event_onClcloseAllSign();
}

//添加项目到列表
function addProjectNode(iconPath, fname, filePath) {
	listNode.push({
		ico: iconPath,
		name: fname,
		path: filePath
	});
}

//显示最近工程列表
function showProjectList() {
	let str = "";
	for (val of listNode) {
		str += `<li sign="${val.path}">
					<img class="projectListIcon" src="${val.ico}" alt="">
					<p class="projectListTitle">${val.name}</p>
					<p class="projectListPath">${val.path}</p>
					<img class="projectListCloseIcon" src="img/close.png" onclick="closeSign('${val.path}')">
				</li>`;

	}
	document.getElementById('projectList').innerHTML = str;
	if (document.getElementById('projectList').innerHTML == "") {
		document.getElementById("projectTip").style.display = "block";
		document.getElementById("clearList").style.display = "none";
	} else {
		document.getElementById("projectTip").style.display = "none";
		document.getElementById("clearList").style.display = "block";
	}
}


//设置公告
function setPublicMessage(str) {
	if (str == "") {
		str = "无内容";
	}
	document.getElementById("MessageText").innerHTML = str;
}


//添加新闻列表
function addNews(iconPath, url = "#", title, text) {
	let str = `<li>
					<img src="${iconPath}" alt="">
					<div class="newArea">
						<a href=${url} class="NewsTitle">${title}</a>
						<p class="NewsContent">${text}</p>
					</div>						
				</li>`;
	document.getElementById("MessageNews").innerHTML += str; //添加
}



function changeTheme(themeName = "Blue"){
	let t_hb = document.getElementsByClassName("HeadBar")[0];
	let t_work = document.getElementsByClassName("Work")[0];
	let t_titles = document.querySelectorAll(".WidgetTitle,.NewsTitle,.projectListTitle");
	let t_contents = document.querySelectorAll(".NewsContent,.projectListPath");
	let t_msgText = document.getElementById("MessageText");
	
	
	let t_color_head_title = "#FFFFFF";
	let t_color_head_background = "#5c2d91";
	let t_color_body_background = "#f2f2f2";
	let t_color_body_title = "#000000";
	let t_color_body_msgText = "#000000";
	let t_color_list_msgText = "gray";
	
	switch(themeName){
		case "Dark":{ //黑色主题
			t_color_head_title = "#FFFFFF";     //主标题颜色
			t_color_head_background = "#1f1f1f";//头部背景颜色
			t_color_body_background = "#2e2e2e";//内容区背景颜色
			t_color_body_title = "#FFFFFF";		//内容区标题
			t_color_body_msgText = "#ababab";   //公告文本
			t_color_list_msgText = "#ababab";   //列表内容
			break;
		}
		case "White":{
			t_color_head_title = "#000000";     //主标题颜色
			t_color_head_background = "#ffffff";//头部背景颜色
			t_color_body_background = "#f7f7f7";//内容区背景颜色
			t_color_body_title = "#000000";		//内容区标题
			t_color_body_msgText = "#1f1f1f";   //公告文本
			t_color_list_msgText = "#ababab";   //列表内容
			break;
		}
		default:{
		}
		case "Blue":{
			break;
		}
	}
	
	t_hb.style.color = t_color_head_title;
	t_hb.style.backgroundColor = t_color_head_background;
	t_work.style.backgroundColor = t_color_body_background ;
	document.body.style.backgroundColor =  t_color_body_background ;
	t_msgText.style.color = t_color_body_msgText;
	for(item of t_titles){
		item.style.color = t_color_body_title;
	}
	for(item of t_contents){
		item.style.color = t_color_list_msgText;
	}
	
	
}