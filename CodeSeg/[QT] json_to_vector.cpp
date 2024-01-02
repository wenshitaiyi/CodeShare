const char * jsongroupinfo="[{/"groupId/" :946838524,/"groupname/" :/"bababa/", /"mask/":1,/"parentid/":946755072}]";
 
Json::Reader reader;
Json::Value json_object;
if (!reader.parse(jsongroupinfo, json_object))
　　return "parse jsonstr error";
SUserChggroup sucg;
VECTOR< SUserChggroup > m_groupInfo;
for(int i = 0; i < json_object.size(); i ++)
{
　　Json::Value &current = json_object[i];
　　sucg.m_groupId = current["groupId"].asInt();
　　sucg.m_groupName = current["groupname"].asString();
　　sucg.m_mask = current["mask"].asInt();
　　sucg.m_parentId = current["parentid"].asInt();
　　m_groupInfo.push_back(sucg);
}

/*****************个人备注****************
 在C++中vector向量存储的同级结构
 这个转化也没啥技术含量，额~~~~~
******************************************/