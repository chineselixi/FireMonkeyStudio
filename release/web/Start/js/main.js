let listNode = [];

window.onload = ()=>{
	
	
	addProjectNode('img/ico.png','HelloWorld','user/desktop/helloworld');
	addProjectNode('img/ico.png','testProject','user/desktop/testProject');
	
	
	addNews("img/news.jpeg","火猴全新平台即将开发完成","据记者了解到，火猴系列开发工具将迎来全新版本。根据内部人员透露，火猴的新平台将会以“火猴2023”来命名，这将是一个全新的跨平台的IDE");
	
	showProjectList();
	
	
}


//设置公告信息
function setTips(msg){
	if(msg == ""){
		msg = "无内容";
	}
	document.getElementById("MessageText").innerHTML = msg;
}

//清理单个列表项目
function closeSign(type){
	let obj = document.querySelectorAll("#projectList li");
	let parent = document.getElementById('projectList');
	for(val of obj){
		if(val.getAttribute('sign') == type){
			parent.removeChild(val);
		}
	}
	
	for(var a = listNode - 1;a >= 0;a--){ //删除本地记录
		if(listNode[a].path == type){
			listNode.splice(a);
		}
	}
	
	if(document.querySelectorAll("#projectList li").length == 0){
		closeAllSign();
	}
}

//删除全部项目
function closeAllSign(){
	document.getElementById("projectList").innerHTML = "";
	document.getElementById("projectTip").style.display = "block";
	document.getElementById("clearList").style.display = "none";
}

//添加项目到列表
function addProjectNode(iconPath,fname,filePath){
	listNode.push(
		{
		ico:iconPath,
		name:fname,
		path:filePath
		}
	);
}

//显示最近工程列表
function showProjectList(){
	let str = "";
	for(val of listNode){
		str += `<li sign="${val.path}">
					<img class="projectListIcon" src="${val.ico}" alt="">
					<p class="projectListTitle">${val.name}</p>
					<p class="projectListPath">${val.path}</p>
					<img class="projectListCloseIcon" src="img/close.png" onclick="closeSign('${val.path}')">
				</li>`;
		
	}
	document.getElementById('projectList').innerHTML = str;
	if(document.getElementById('projectList').innerHTML == ""){
		document.getElementById("projectTip").style.display = "block";
		document.getElementById("clearList").style.display = "none";
	}
	else{
		document.getElementById("projectTip").style.display = "none";
		document.getElementById("clearList").style.display = "block";
	}
}


//设置公告
function setPublicMessage(str){
	if(str == ""){
		str = "无内容";
	}
	document.getElementById("MessageText").innerHTML = str;
}


//添加新闻列表
function addNews(iconPath,title,text){
	let str = `<li>
					<img src="${iconPath}" alt="">
					<div class="newArea">
						<a href="#" class="NewsTitle">${title}</a>
						<p class="NewsContent">${text}</p>
					</div>						
				</li>`;
	document.getElementById("MessageNews").innerHTML += str;//添加
}