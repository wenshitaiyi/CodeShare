
/************************************************************************************************************************/


function ConfigInfoMap(infoMap)
{
	infoMap.set('姓名 *','王凤娟');
	infoMap.set('性别 *','女');
	infoMap.set('国籍 *','中国');
	infoMap.set('籍贯 *','河北省石家庄市深泽县赵八镇田家庄');
	infoMap.set('民族 *','汉族');
	infoMap.set('婚姻状况 *','未婚');
	infoMap.set('文化程度 *','大学本科');
	infoMap.set('户籍类型 *','外地');
	infoMap.set('职业 *','其他');
	infoMap.set('既往史 *','无');
	infoMap.set('家族疾病史 *','无');
	infoMap.set('遗传病史 *','无');
	infoMap.set('体检：血压 *','85');
	infoMap.set('体检：身高 *','151');
	infoMap.set('体检：体重 *','48');
	infoMap.set('体检：腰围 *','70');
	infoMap.set('体检：臀围 *','88');
	infoMap.set('医疗费用类型 *','自费');
	infoMap.set('医保号（社会医疗保险请填写）','130128199408111524');
	infoMap.set('现住址 *','北京市昌平区龙禧苑一区8号楼1单元601');
	infoMap.set('工作单位 *','中梦网络科技有限公司');
	infoMap.set('年龄 *','26');
	infoMap.set('电话 *','15229315932');
	infoMap.set('身份证号 *','130128199408111524');
	infoMap.set('预约疫苗名称（几价疫苗） *','四价疫苗');
	infoMap.set('半个月内有无感冒发烧 *','无');
	infoMap.set('备孕哺乳期 *','否');
	infoMap.set('一个月内是否打过其他针 *','否');
	infoMap.set('有无食物、药物过敏史 *','无');
	infoMap.set('有无高热惊厥、癫痫史 *','无');
	infoMap.set('三个月内是否使用过免疫球蛋白或血液制品 *','否');
	infoMap.set('有无家族遗传病史 *','无');
	infoMap.set('有无其他不舒服例如腹泻、呕吐等等 *','无');
	infoMap.set('是否有器质性病变例如肝炎、肾炎、脏器类病症 *','无');
	infoMap.set('有无其他基础病例如糖尿病。高血压、心脏病等 *','无');
	infoMap.set('一个月内吃过什么药 *','无');
	infoMap.set('请选择针次 *','第三针');
}


//set text for input node
function SetText(tdNode,text)
{
	if(!tdNode) return;
	var inputNode = tdNode.querySelector('input');
	if(!inputNode) return;
	inputNode.value = text;
}

function SelectRadio(tdNode,name)
{
	if(!tdNode) return;
	var radioList = tdNode.querySelectorAll('input.wgj-radio');
	for(var i=0;i<radioList.length;i++)
	{
		var text = radioList[i].value;
		text = text.replace(/\s*/g,"");
		radioList[i].checked = (text==name);
	}
}

var infoMap = new Map();
var pickNodeList=[];

var trList = document.querySelectorAll('form tbody tr');
ConfigInfoMap(infoMap);

for(var i=0;i<trList.length-1;i++)
{
	var tdNode = trList[i].querySelector('td');
	if(tdNode)
	{
		var inText = tdNode.innerText;
		if(!infoMap.has(inText) || pickNodeList.indexOf(inText)!=-1) continue;


		var sibTdNode = trList[i+1].querySelector('td');
		if(!sibTdNode) continue;

		var showLog = false;

		var inputNode = sibTdNode.querySelector('input');
		if(inputNode)
		{
			showLog = true;
			var inType = inputNode.type;
			if(inType=='text' || inType=='digit')
			{
				SetText(sibTdNode,infoMap.get(inText));
			}
			else if(inType=='checkbox' || inType=='radio')
			{
				SelectRadio(sibTdNode,infoMap.get(inText));
			}
		}

		if(showLog)
		{
			console.log('GetOne'+inText+':'+infoMap.get(inText));
		}

		pickNodeList.push(inText);
	}
}

document.querySelectorAll("select")[0].selectedIndex = 1;
