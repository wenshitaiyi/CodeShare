function sleep(milliseconds) {  
	return new Promise(resolve => setTimeout(resolve, milliseconds));
} 

async function getAllLinks(){
	var outStr='';
	var nameList=document.querySelectorAll('.f_name_title');
	for(var i=0;i<nameList.length;i++){
		var nameSpan = nameList[i];
		nameSpan.click();
		var str1=nameSpan.innerText;
		await sleep(1300);
		var str2=document.querySelector('#f_sha1').innerText.replace('\n',' ');
		outStr=outStr+str1+'：'+str2+'\n';
	}
	console.log(outStr);
}
getAllLinks();