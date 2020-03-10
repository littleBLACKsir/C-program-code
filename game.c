#include "game.h"
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#define SEP "------------------------------------------------------------------------------"
#define COL 78
#define MARGIN_X 20     //左边距
#define MAP_START_Y 3
#define MAP_END_Y 11
#define INFO_START_Y 12
#define INFO_END_Y 19
#define MAINMENU_START_Y 20
int X=3,Y=2;
int choice=-1;
player players[]={
    {9527,"徐小徐","bohu.tang",10000,3,100,1000,5000,50000,10000,.coord.X=3,.coord.Y=1},
    {9527,"邓小邓","bohu.tang",20000,5,200,2000,5000,50000,100000,.coord.X=3,.coord.Y=1}
};
monster monsterArray[]={

    //一级怪物刷新点
    {1,"海绵宝宝",1,100,5,8,5,10,5,1,{1,0}},{4,"恶魔小七",1,100,5,8,5,10,5,1,{0,5}},
    {6,"海阔天空鸟",1,100,5,8,5,10,5,1,{2,0}},{6,"小矮人",1,100,5,8,5,10,5,1,{0,7}},
    {6,"小花蛇",1,100,5,8,5,10,5,1,{3,0}},{6,"强盗",1,100,5,8,5,10,5,1,{0,5}},
    {1,"海绵宝宝",1,100,5,8,5,10,5,1,{3,0}},{1,"海绵宝宝",1,100,5,8,5,10,5,1,{3,5}},
    {1,"海绵宝宝",1,100,5,8,5,10,5,1,{5,5}},{1,"海绵宝宝",1,100,5,8,5,10,5,1,{6,7}},
    {1,"海绵宝宝",1,100,5,8,5,10,5,1,{7,7}},{1,"海绵宝宝",1,100,5,8,5,10,5,1,{4,5}},
    {4,"恶魔小七",1,100,5,8,5,10,5,1,{2,5}},{4,"恶魔小七",1,100,5,8,5,10,5,1,{4,5}},
    {4,"恶魔小七",1,100,5,8,5,10,5,1,{1,7}},{4,"恶魔小七",1,100,5,8,5,10,5,1,{7,5}},
    {6,"海阔天空鸟",1,100,5,8,5,10,5,1,{6,3}},{6,"海阔天空鸟",1,100,5,8,5,10,5,1,{5,2}},
    {6,"海阔天空鸟",1,100,5,8,5,10,5,1,{3,3}},{6,"海阔天空鸟",1,100,5,8,5,10,5,1,{4,4}},
    {6,"小矮人",1,100,5,8,5,10,5,1,{2,7}},{6,"小矮人",1,100,5,8,5,10,5,1,{3,6}},
    {6,"小矮人",1,100,5,8,5,10,5,1,{4,5}},{6,"小矮人",1,100,5,8,5,10,5,1,{5,4}},
    {6,"小花蛇",1,100,5,8,5,10,5,1,{3,5}},{6,"小花蛇",1,100,5,8,5,10,5,1,{7,0}},
    {6,"强盗",1,100,5,8,5,10,5,1,{7,2}},{6,"强盗",1,100,5,8,5,10,5,1,{7,5}},
    //二级怪刷新点
    {2,"五百强凤姐",2,200,8,10,10,20,10,1,{0,1}},{6,"海洋亚龙",2,200,8,10,10,20,10,1,{0,5}},
    {6,"烈火鸟",2,200,8,10,10,20,10,1,{0,7}},{6,"火焰狮子",2,200,8,10,10,20,10,1,{0,4}},
    {2,"五百强凤姐",2,200,8,10,10,20,10,1,{1,1}},{2,"五百强凤姐",2,200,8,10,10,20,10,1,{2,1}},
    {2,"五百强凤姐",2,200,8,10,10,20,10,1,{4,2}},{2,"五百强凤姐",2,200,8,10,10,20,10,1,{5,1}},
    {6,"海洋亚龙",2,200,8,10,10,20,10,1,{4,4}},{6,"海洋亚龙",2,200,8,10,10,20,10,1,{4,5}},
    {6,"海洋亚龙",2,200,8,10,10,20,10,1,{7,0}},{6,"海洋亚龙",2,200,8,10,10,20,10,1,{6,6}},
    {6,"烈火鸟",2,200,8,10,10,20,10,1,{5,3}},{6,"烈火鸟",2,200,8,10,10,20,10,1,{3,4}},
    {6,"烈火鸟",2,200,8,10,10,20,10,1,{4,7}},{6,"烈火鸟",2,200,8,10,10,20,10,1,{5,7}},
    {6,"火焰狮子",2,200,8,10,10,20,10,1,{7,0}},{6,"火焰狮子",2,200,8,10,10,20,10,1,{7,7}},
    {6,"火焰狮子",2,200,8,10,10,20,10,1,{2,1}},{6,"火焰狮子",2,200,8,10,10,20,10,1,{2,2}},
    //三级怪物刷新点
    {5,"猩红小舞",3,500,15,15,30,40,35,1,{5,0}},{5,"远古蔚蓝魔象",3,500,15,15,30,40,35,1,{6,0}},
    {5,"疯狂豹",3,500,15,15,30,40,35,1,{6,0}},{5,"食人草",3,500,15,15,30,40,35,1,{2,0}},
    {5,"猩红小舞",3,500,15,15,30,40,35,1,{7,1}},{5,"猩红小舞",3,500,15,15,30,40,35,1,{0,5}},
    {5,"猩红小舞",3,500,15,15,30,40,35,1,{0,7}},{5,"猩红小舞",3,500,15,15,30,40,35,1,{1,7}},
    {5,"远古蔚蓝魔象",3,500,15,15,30,40,35,1,{5,2}},{5,"远古蔚蓝魔象",3,500,15,15,30,40,35,1,{4,4}},
    {5,"远古蔚蓝魔象",3,500,15,15,30,40,35,1,{3,0}},{5,"远古蔚蓝魔象",3,500,15,15,30,40,35,1,{3,2}},
    {5,"疯狂豹",3,500,15,15,30,40,35,1,{7,3}},{5,"疯狂豹",3,500,15,15,30,40,35,1,{1,2}},
    {5,"疯狂豹",3,500,15,15,30,40,35,1,{1,5}},{5,"疯狂豹",3,500,15,15,30,40,35,1,{2,7}},
    {5,"食人草",3,500,15,15,30,40,35,1,{2,3}},{5,"食人草",3,500,15,15,30,40,35,1,{7,7}},
    {5,"食人草",3,500,15,15,30,40,35,1,{2,5}},{5,"食人草",3,500,15,15,30,40,35,1,{4,5}},
    //四级怪刷新点
    {7,"老夫子",4,700,20,18,50,100,80,1,{7,1}},{7,"机器怪",4,700,20,18,50,100,80,1,{6,2}},
    {7,"剑魔",4,700,20,18,50,100,80,1,{5,4}},{7,"魔狐",4,700,20,18,50,100,80,1,{2,3}},
    {7,"老夫子",4,700,20,18,50,100,80,1,{7,6}},{7,"老夫子",4,700,20,18,50,100,80,1,{7,2}},
    {7,"老夫子",4,700,20,18,50,100,80,1,{5,1}},{7,"老夫子",4,700,20,18,50,100,80,1,{4,1}},
    {7,"机器怪",4,700,20,18,50,100,80,1,{5,7}},{7,"机器怪",4,700,20,18,50,100,80,1,{4,2}},
    {7,"机器怪",4,700,20,18,50,100,80,1,{1,1}},{7,"机器怪",4,700,20,18,50,100,80,1,{1,5}},
    {7,"剑魔",4,700,20,18,50,100,80,1,{7,4}},{7,"剑魔",4,700,20,18,50,100,80,1,{6,4}},
    {7,"剑魔",4,700,20,18,50,100,80,1,{5,0}},{7,"剑魔",4,700,20,18,50,100,80,1,{5,2}},
    {7,"魔狐",4,700,20,18,50,100,80,1,{5,3}},{7,"魔狐",4,700,20,18,50,100,80,1,{2,4}},
    {7,"魔狐",4,700,20,18,50,100,80,1,{0,3}},{7,"魔狐",4,700,20,18,50,100,80,1,{2,1}},
    //五级怪刷新点
    {3,"地狱男爵",5,1000,35,20,80,150,100,1,{0,2}},{3,"烈风豹",5,1000,35,20,80,150,100,1,{0,2}},
    {3,"巫师",5,1000,35,20,80,150,100,1,{0,2}},
    //六级怪刷新点
    {6,"杨过之雕",6,1500,50,50,150,250,150,1,{0,0}},{6,"鹰眼",6,1500,50,50,150,250,150,1,{0,0}},
    {6,"麦哲伦",6,1500,50,50,150,250,150,1,{0,0}},
    //七级怪刷新点
    {6,"烈焰魔男",7,2200,80,80,250,400,300,1,{0,0}},{6,"青龙",7,2200,80,80,250,400,300,1,{0,0}},
    {6,"霸王龙",7,2200,80,80,250,400,300,1,{0,0}},
    //八级怪刷新点
    {6,"锟鹏鸟",8,3500,150,150,500,1000,500,1,{0,0}},{6,"齐天大圣",8,3500,150,150,500,1000,500,1,{0,0}},
    //九级怪刷新点
    {6,"玉皇大帝",9,5000,250,300,1000,3000,1500,1,{0,0}},
};
Prop PropArray[]={
 {1,"帝皇天烈剑",1,5,5000,Weapon,.minAttack=5,.maxAttack=25,"上古黄帝之剑"},
 {2,"天蝎盾",2,5,10000,Armor,.minDefence=2,.maxDefence=6,"最强之盾"},
 {3,"玉液琼浆",3,5,15000,Con,.minPower=1,.maxPower=4,"古娜拉黑暗之神"},
};
map maparray[8][8]={
   {
       {1,"恶人谷",1,{0,0},"恶人满地，心中向善方能成就正果"},{1,"黑木崖",1,{1,0},"凶恶之地，闲人免进"},
       {1,"百花谷",1,{2,0},"这里都是仙气，适合少男少女来学习"},{1,"风雪山",1,{3,0},"冰雪奇缘，一首 Let it go 送给你"},
       {1,"蝴蝶谷",1,{4,0},"这里适合女同学修炼"},{1,"神庙",1,{5,0},"成神圣地"},
       {1,"五花岗",1,{6,0},"奇袭，智取五花岗"},{1,"狐火岭",1,{7,0},"火元素才是这里的主旨"}
   },
    {
       {1,"玩偶山庄",1,{0,1},"这里很奇怪，充满了奇特"},{1,"铁马堡",1,{1,1},"骑兵的圣地，今天，我胡汉三又回来了 "},
       {1,"花果山",1,{2,1},"传说中大圣诞生之地，一棍开天地，两棍移山海，三棍破晚敌，"},{1,"毒堡",1,{3,1},"宗师与唐门恩怨很深，毒不死亦善亦恶"},
       {1,"土地庙",1,{4,1},"土地老儿速来相见"},{1,"关帝庙",1,{5,1},"习武之人都尊敬的地方，习武圣地"},
       {1,"八神岭",1,{6,1},"拳皇97(木马病毒版)is loading..."},{1,"三中殿",1,{7,1},"这里...传说中有很多发廊..."}
   },
    {
       {1,"精灵洞",1,{0,2},"钟声响起归家的讯号在他生命里仿佛带点唏嘘黑色肌肤给他"},{1,"斗宗唐",1,{1,2},"想成为万人敬仰的斗宗吗？那就充值人民币吧，让我们人民币玩家日渐壮大！"},
       {1,"花仙地",1,{2,2},"想见花仙子吗？请联系作者进行充值人民币"},{1,"敏唐",1,{03,2},"想要速度吗？那就充值人民币吧，让我们人民币玩家日渐壮大！"},
       {1,"爆裂魔地",1,{4,2},"所谓爆裂，即为凤凰浴火重生，否极泰来，修炼圣地"},{1,"力堂",1,{5,2},"想要力量吗？那就充值人民币吧，让我们人民币玩家日渐壮大！"},
       {1,"猎户山",1,{6,2},"这里拥有世界上的奇特动物"},{1,"火神殿",1,{7,2},"火的圣地，炎帝的府邸"}
   },
    {
       {1,"西山",1,{0,3},"这里充满了妖魔鬼怪"},{1,"修仙地",1,{1,3},"一株草可诸天灭地，速来桂电修仙"},
       {1,"封魔山",1,{2,3},"不疯魔，不成活"},{1,"小徐作坊",1,{3,3},"一个充满奇迹的地方"},
       {1,"小邓庙堂",1,{4,3},"风中风中 心里冷风，吹失了梦，事未过去 就已失踪，此刻有种种心痛，心中心中 一切似空，天黑天光都似梦，迷迷惘惘 聚满心中"},{1,"孔雀山庄",1,{5,3},"孔雀山庄，这是一个神秘的地方，传说有很多的秘象，孔雀升天与凤凰大战一场，还有更多能人"},
       {1,"灭霸崖",1,{6,3},"听说托尼你很牛i？凡人躯体，可敢一战？（内心慌得一匹，毕竟钢铁侠也能打响指）"},{1,"六合塔",1,{7,3},"道生一，一生二，三生万物，六合....六合成塔！。。。塔"}
   },
    {
       {1,"天山",1,{0,4},"天上有云，为天山的外围，拨开迷雾见重山"},{1,"楼兰",1,{1,4},"胡歌一日未来，我便一日不走"},
       {1,"白驼山",1,{2,4},"和尚的聚集地，尚者，修人成道"},{1,"野猪林",1,{3,4},"林冲大闹野猪林"},
       {1,"水晶洞",1,{4,4},"水晶洞传闻孕育了凤凰"},{1,"天蚕洞",1,{5,4},"一记天蚕脚文明天下"},
       {1,"黑风岭",1,{6,4},"蒂奇的居住之地，黑暗果实诞生的地方，最终决战海贼王的地方"},{1,"冰火岛",1,{7,4},"冰火两重天，此地为修炼肉体的圣地"}
   },
    {
       {1,"迷宫",1,{0,5},"你是我的眼，带我穿越拥挤的...迷宫"},{1,"凌霄城",1,{1,5},"一日大鹏展翅，冲上凌霄，即为鲲鹏九万里。。。都是些啥JB玩意"},
       {1,"轩辕岭",1,{2,5},"古有三皇五帝，轩辕帝为其一，大战葬身于此，世人唏嘘"},{1,"华山",1,{3,5},"9527，华安在此"},
       {1,"嵩山",1,{4,5},"嵩山就是梁山好汉的总舵，惩奸除恶，我为枭雄h"},{1,"紫禁城",1,{5,5},"此地戒备森严，城内嫔妃欢笑，大内密探何在？"},
       {1,"快活林",1,{6,5},"水浒兄弟的快活圣地？或许吧？"},{1,"神龙岛",1,{7,5},"请问施主召集完七颗龙珠了？何人敢唤我神龙"}
   },
    {
       {1,"西域",1,{0,6},"这里充满了西域文化"},{1,"葫芦谷",1,{1,6},"传说中有七个葫芦娃的故事就发生在这里"},
       {1,"唐门",1,{2,6},"唐三先祖在此，海神三叉戟速来，谁敢动我的小舞？"},{1,"终南山",1,{3,6},"什么病毒不过尔尔，等我还你们安逸！"},
       {1,"石窟",1,{4,6},"敦煌石窟充满了文化气息你听说过嘛？没错，这里也是"},{1,"客栈",1,{5,6},"休息的客栈，修炼累了可以来转转哦"},
       {1,"玉皇顶",1,{6,6},"忘记无忌那个叫什么顶了，就暂且当这是无忌的总舵吧，hhh"},{1,"灵蛇岛",1,{7,6},"你知道python的中文是什么嘛？hhh，蟒蛇，可惜python我正在学，只能copy一下老九的c语言来拜托小白的标签啦！等我成为了大牛我会回来的！！！"}
   },
    {
       {1,"封皇庙",1,{0,7},"等我学富五车的一天，我就封皇了，不过有那天嘛？？？"},{1,"镇魔府",1,{1,7},"镇魔岛很low嘛？好像是有一丢丢....算了，不换了"},
       {1,"水方城",1,{2,7},"水方，顾名思义，所谓伊人，在水一方。程序员有女孩子的？没听说过"},{1,"积善堂",1,{3,7},"程序员嘛，多来这里逛逛，不然就是从入门到入狱系列，我爬我爬我爬爬爬"},
       {1,"爱情岛",1,{4,7},"落红不是无情物，化作春泥更护花"},{1,"桃花岛",1,{5,7},"郭靖和某人在这里相爱相伴"},
       {1,"科学岛",1,{6,7},"科学的世界一片灰暗，等待有志之士前来探索"},{1,"罪恶殿",1,{7,7},"罪恶的地方往往是修炼善心最好的地方，没错，让你从入门到入坟，就是这么罪恶。hhh"}
   }

};
Martial martials[] ={
    {1, "少林派",   "正派", .hqCoord.X=1, .hqCoord.Y=4, 1, "中华武学的泰斗，明末，少林众多的人才中，以悟空和箭神二人排为一等。其中，悟空出家为僧，箭神乃俗家弟子。当时江湖人称少林双绝。少林寺中众僧在两大长老的带领下参加了江浙沿海抗击倭寇的战斗，在各路应募兵马中表现得最为骁勇。但正因抗倭之事，也使江湖中的众多门派产生了矛盾，其中首推少林和日月神教。悟空、箭神曾几度带领江湖同仁攻上光明顶，但由于日月神教和血河两派结为同盟，更何况邪派中高手如云，所以几次围剿未果而终，黑白两道都损失惨重"},
    {2, "武当派",   "正派", .hqCoord.X=3, .hqCoord.Y=4, 1, "武当在江湖上与少林齐名，有‘北崇少林’‘南尊武当’之说。 武当新一代的首领人物，是一位谦谦君子，一张轮廓分明的脸上总是带着爽朗的笑容，就连他的仇敌都不能不承认他是条少见的男子汉。凡人从十八岁崛起江湖，身经大小三十三战，至今从未败过一次。凡人一生中最不能忍受的两件事就是失败和错误。 "},
    {3, "丐帮",     "正派", .hqCoord.X=2, .hqCoord.Y=6, 1, "丐帮是中原武林中人数最为众多的一个门派，也是天下第一大帮派，以遍布天下乞丐的乞丐组成，分为污衣帮和净衣帮。丐帮中人大多都是社会地位比较低的人，但他们各个铮铮硬骨，品格高尚，很少出现卑劣之人。丐帮新一代众多弟子以天葵为首，除暴安良、行侠丈义、抑强扶弱，所作所为为天下人所津津乐道。"},
    {4, "全真教",   "正派", .hqCoord.X=2, .hqCoord.Y=3, 1, "全真属于道教的分支之一。现今全真教中最有权威的人是一个瘦瘦小小的人，长着一双冷冷淡淡好象永远不会有什么变化的眼睛，看起来仿佛是灰色的。但他又是一个非常讲究的人，他喜欢紫色，喜欢名马佳人华衣美酒，喜欢享受。对每一件事情他都非常的挑剔，做的每一件事都经过精密计划，绝不肯多浪费一分力气，也不会有一点疏忽。这就是全真海雅。"},
    {5, "五岳剑派", "正派", .hqCoord.X=1, .hqCoord.Y=3, 1, "泰山派，恒山派，衡山派，华山派，嵩山派结为同气枝连的的五岳剑派，在江湖上扬名立万。五派中人一向面和心不和，所以五派的式微不是由于外敌入侵，而纯粹是内部矛盾激化走向内耗的结果，内部的勾心斗角虽然常常以抗倭为借口出现，实则是为了掌握五岳生杀大权。"},
    {6, "四川唐门", "正派", .hqCoord.X=2, .hqCoord.Y=2, 1, "唐门在江湖上以暗器闻名。但自从唐门的唐老太太过世后唐家堡一度家道中落，加之唐甜为称霸武林挑起纷争，又使唐门陷入了再度的浩劫，几乎一蹶不振。在这种危难的时刻唐门出现了一群新生力量：唐纾、唐斩、唐缺、唐玉。他们整顿内务，肃清奸佞，打出了匡复武林正义的旗帜，并且在江湖上行侠仗义，挽回了唐门的声誉，使唐门成为了江湖上的名门正派。"},
    {7, "大理段氏", "正派", .hqCoord.X=5, .hqCoord.Y=1, 1, "大理段氏人丁众多，高手如云。其中有一位名扬江湖顶尖女侠——香雪儿。香雪儿面相灵秀，肤色白皙，但微显瘦弱，看上去弱不禁风却身怀绝世武功，已深得大理武功心得。"},
    {8, "天山派",   "正派", .hqCoord.X=0, .hqCoord.Y=0, 1, "天山派是名门正派，也是目前江湖中最为团结的一个门派。天山派也是江湖中女弟子最为众多的一个门派，且各个武功造诣不凡，相貌清秀。"},
    {9, "古墓派",   "正派", .hqCoord.X=3, .hqCoord.Y=3, 1, "古墓派这一代的传人名叫暄雯，是一女子，来历不明。暄雯生性娴静，长相俊美，举止飘逸，但做事情却不似师祖小龙女，倒颇有一点杨过的风格，武功修为深不可测，同样喜穿白衣。此派轻功卓越，剑法、拳法灵动妙绝，更是全真教的克星。古墓传人的处世原则是“事不关己，高高挂起”，过着与世无争的日子，但是如果有人冒犯了古墓传人，那他一定会死得很惨。"},
    {10, "名捕门",  "正派", .hqCoord.X=1, .hqCoord.Y=1, 1, "名捕门历属与官府，但其中也不乏在江湖上闯出名堂的武林高手。名捕门一等一的人才中有一位绰号叫‘惊天泣鬼’的，此人从不以真面目视人，总是在幕后策划一些事情。"},
    {11, "日月神教","邪派", .hqCoord.X=6, .hqCoord.Y=1, 1, "由于该教高手众多，并彼此互不相服，所以教务混杂。教中弟子多为邪恶之徒，专与名门正派作对，杀人良多，罪恶昭彰，故被江湖正派之人贬为魔教。"},
    {12, "权力帮",  "邪派", .hqCoord.X=4, .hqCoord.Y=0, 1, "邪派之一，目前派中最高首脑为一叫阿飞的年轻人。阿飞，一个表面上异常忧悒的人。没有与其交过手的武林高手，无法想象他那弱不禁风的身躯隐藏着那么大的潜力，更不能想象他是如何用支撑起权利帮的担子的。"},
    {13, "五毒教",  "邪派", .hqCoord.X=2, .hqCoord.Y=0, 1, "一个以使毒为专长的门派，派中人各个都是用毒高手。此派高手人称梦魇，其人使毒已入化境，令人难以琢磨，江湖同道对其莫不绕道而行。此人品行时好时坏，但坚韧卓绝，嗜武成痴。"},
    {14, "神龙教",  "邪派", .hqCoord.X=2, .hqCoord.Y=7, 1, "神龙教是江湖邪派，由于教址远离中原，所以不大干预中原武林的血腥杀戮。目前神龙教有两位高手一为刀神，此人武功高深莫测，性格孤僻冷傲，不喜与人接近。二为恶龙，武功高强但脾气暴躁，做事没有耐性。"},
    {15, "青龙会",  "邪派", .hqCoord.X=5, .hqCoord.Y=6, 1, "江湖上绵延数百年的一个神秘组织。青龙会下分十二堂，分别以月为代号。"},
    {16, "桃花岛",  "亦正亦邪", .hqCoord.X=4, .hqCoord.Y=7, 1, "自从东邪黄药师扬名立万于此后，他的传人就在这里绵延不绝，竟将桃花岛建成了门派的总舵。桃花岛黄药师的关门弟子程英一生未嫁，在岛上收了几个徒弟，桃花岛的武功因此得到延续和发扬。"},
    {17, "锦衣卫",  "亦正亦邪", .hqCoord.X=1, .hqCoord.Y=5, 1, "大内锦衣卫中人才济济，尤其是雷神，此人野心勃勃，自幼练得一身大力金刚功，号称刀枪不入，武功实是深不可测。而且为人机智，精通兵法，行兵时能将千军万马人使得如同数十万般威力十足。"},
    {18, "血河派",  "亦正亦邪", .hqCoord.X=5, .hqCoord.Y=0, 1, "自从血河派的掌门一代大侠方歌吟飘然而去后，血河派日益衰落。血河派活动的范围也越来越少，基本上只限与龙门石窟。而江湖上的九大门派已经把血河派视为邪魔歪道。并已传出英雄令，只要九大门派的门人遇上血河派的人，一律格杀无论。在江湖上已经没有什么血河派的人在行走。除了无恨！没有人知道他来自何方，人们只知道他来自血河派。没有人知道他的武功有多高，因为看见他的剑的人都已经......无恨是武林中的一个谜，现隐居在天山，相传是为了一名叫若寒的女子。相传血河弟子花无缺已深得无恨真传，在无恨隐居江湖期间代理血河的一切帮中事务。花无缺为人善良真诚，在江湖上人缘甚好，并将血河派内外事务打理得井井有条。"},
    {19, "通通吃",  "亦正亦邪", .hqCoord.X=7, .hqCoord.Y=3, 1, "江湖上一个神秘的门派，创始人，武功不祥。总舵设在通吃岛，教中首领人物——辉翰。此人手段严酷，以威服人。平常不轻易踏足中原武林，潜心修炼武功。"},
    {20, "玩偶山庄","亦正亦邪", .hqCoord.X=0, .hqCoord.Y=6, 1, "江湖上一个神秘的门派，创始人，武功不祥。总舵就在玩偶山庄，教中首领人物——阳光。玩偶山庄门人众多，但大都绝迹江湖，只有阳光经常独自浪迹江湖并闯出了名堂，所以武林中人才知有这么一个门派存在。"}
};
player *currplayer;
void Init()//初始化游戏数据
{
    //int choice;
    printf("请确定登录玩家:\n1是徐小徐，2是邓小邓\t");
    setposition(0,2);
    scanf("%d",&choice);
    setposition(0,0);
    printf("                   \n                   \n  ");
    currplayer =& players[choice-1];     //设置默认登录玩家为1号
    currplayer->Weapon=PropArray[0];
    currplayer->Armor=PropArray[1];
}
void show()//显示全部数据
{
    int Propcount = sizeof(PropArray)/sizeof(Prop);
    int i;
    for( i=0; i < Propcount; i++)
    {
        printf("%d\t%s\t%.0lf\t%s\n",PropArray[i].id,PropArray[i].name,PropArray[i].price,PropArray[i].desc);
        switch(PropArray[i].type)
        {
            case Weapon:
            printf("最小攻击力：%d\t最大攻击力：%d\t",PropArray[i].minAttack,PropArray[i].maxAttack);
        }
    }
}

/*  显示游戏的欢迎信息*/
void showwelcome()
{
    setposition(MARGIN_X,0);
    printf("%s",SEP);
    setposition(MARGIN_X,1);
    printf(" |");
    setposition(MARGIN_X+34,1);
    printf("欢迎玩家%s",currplayer->name);
    setposition(MARGIN_X+77,1);
    printf("|");
    setposition(MARGIN_X,2);
    printf("%s",SEP);
}
/* 显示门派信息 */
void showattribute()
{
    Clear(MARGIN_X,INFO_START_Y,7);
    int i,j;
    char * martialIntro = NULL;     //门派介绍
    Martial *currMartial = NULL;
    for(i = 0; i < 20; i++)
    {
        if(X == martials[i].hqCoord.X && Y == martials[i].hqCoord.Y)//门派总部坐标与当前玩家坐标相等时
        {
            currMartial = &martials[i];
            martialIntro = martials[i].description;
            break;
        }
    }
    if(martialIntro == NULL)
    {
        Clear(MARGIN_X,INFO_START_Y+1,5);
        setposition(MARGIN_X+25,INFO_START_Y);
        printf("当前地图：《%s》",maparray[Y][X].name);
        setposition(MARGIN_X+10,INFO_START_Y+1);
        printf("该地图暂时没有总舵，请日后再来吧！");
        return;
    }
    j = 0;
    setposition(MARGIN_X, 12);
    if(currMartial != NULL)
    {
        setposition(MARGIN_X+10,INFO_START_Y);
        printf("                                ");
        setposition(MARGIN_X+10,INFO_START_Y);
        printf("\t\t\t<%s>的总舵是<%s>", maparray[Y][X].name, currMartial->name);
    }
   /* else
    {
        setposition(MARGIN_X, 18) ;
        return;
    }*/
    setposition(MARGIN_X+10,INFO_START_Y+1);
    int length = strlen(martialIntro);
    if(length > 300) length = 300;
    for(i = 0; i < length; i++)
    {
       if(i!=0 &&i % 60==0)                //控制每行只打印60个字符
        {
            setposition(MARGIN_X+10,INFO_START_Y+1+i/60);       //i/60就是加第几行的意思，原本的光标在INFO_START_Y+1
        }
        printf("%c", *(martialIntro + i));
    }

}
/*  显示游戏地图  */
void showmap(){
    int i,j;
    printf("\n");
    for(i=0;i<8;i++)
    {
        setposition(MARGIN_X,MAP_START_Y+i);
        for(j=0;j<8;j++)
        {   if(j==0)
            printf("|  ");
            if(i == Y&& j == X)
            {
                setcolor(4,7);
            }
            printf("%-9s",maparray[i][j].name);
            setcolor(10,0);
        }
        setposition(MARGIN_X+77,3+i);
        printf("|");
    }
    setposition(MARGIN_X,MAP_END_Y);
    printf(SEP);
    showmapinfo();                  //打印地图信息
}
void showmapinfo()
{
    //清空地图
    Clear(MARGIN_X,INFO_START_Y,7);
    //重新打印
    setposition(MARGIN_X+25,INFO_START_Y);
    printf("当前地图：《%s》",maparray[Y][X].name);
    setposition(MARGIN_X+10,INFO_START_Y+1);        //移动光标到下一行
    //printf("%s",maparray[Y][X].desc);     //直接打印
    char * desc =maparray[Y][X].desc;       //定义一个指针变量来存放这个数组
    int desclen=strlen(desc);
    int i;
    for(i=0; i < desclen ; i++)
    {
        if(i!=0 &&i % 60==0)                //控制每行只打印60个字符
        {
            setposition(MARGIN_X+10,INFO_START_Y+1+i/60);       //i/60就是加第几行的意思，原本的光标在INFO_START_Y+1
        }
        printf("%c",desc[i]);
    }
}
/* 显示游戏地图下方的信息 */
void showinformation(){
    setposition(MARGIN_X,INFO_START_Y);
    int i;
    for(i=0; i<7 ; i++)
    {
    setposition(MARGIN_X,INFO_START_Y+i);
    printf("|");
    setposition(MARGIN_X + 77, INFO_START_Y + i);
    printf("|");
    }
    setposition(MARGIN_X,INFO_START_Y+7);
   printf(SEP);
}
/* 显示游戏的主菜单 */
void showmainmenu(){
    setposition(MARGIN_X,MAINMENU_START_Y);
    printf("游戏菜单：\n");
    setposition(MARGIN_X,MAINMENU_START_Y+1);
    printf("1.自我欣赏");
    setposition(MARGIN_X,MAINMENU_START_Y+2);
    printf("2.寻找怪物");
        setposition(MARGIN_X,MAINMENU_START_Y+3);
    printf("3.回总舵");
    setposition(MARGIN_X,MAINMENU_START_Y+4);
    printf("4.查看当前地图门派信息");
}
void processmainmenu(char key)
{
    switch(key)
    {
        case '1':               //自我欣赏
            showplayerinfo();
            break;
        case '2':               //寻找怪物
            showmonsters();
            break;
        case '3':               //回总舵
            ShowHQ();
            break;
        case '4':               //查看门派
            showattribute();
            break;
         case '5':               //自我欣赏
            break;
    }
}
void showplayerinfo()
{
    Clear(MARGIN_X,INFO_START_Y,7);
    setposition(MARGIN_X+20,INFO_START_Y);
    printf("大侠《%s》个人资料",currplayer->name);
    setposition(MARGIN_X,INFO_START_Y+1);
    printf("等级：%d\t血量：%d\t法力值：%d\t经验值；%d",currplayer->level,currplayer->hp,currplayer->mp,currplayer->exp);
    setposition(MARGIN_X,INFO_START_Y+2);
    printf("当前武器：%s\t%s\t攻击力范围%d-%d",currplayer->Weapon.name,currplayer->Weapon.desc,currplayer->Weapon.minAttack,currplayer->Weapon.maxAttack);
    setposition(MARGIN_X,INFO_START_Y+3);
    printf("当前防具：%s\t%s\t防御力范围%d-%d",currplayer->Armor.name,currplayer->Armor.desc,currplayer->Armor.minDefence,currplayer->Armor.maxDefence);
}
void showmonsters()
{
    char * levelnames[]={"乳臭未干","初出茅庐","粗通皮毛","青年才俊","略有小成","出类拔萃","心领神会","所向无敌","天人合一"};
    Clear(MARGIN_X,INFO_START_Y,7);
    setposition(MARGIN_X+10,INFO_START_Y);
    //先获得当前的怪物总数
    int monstercount = sizeof(monsterArray)/sizeof(monster);    //当前怪物总量
    int monsterindexs[9];
    int currmapmonstercount = 0;  //当前怪我总数
    int i;
    for (i = 0; i < monstercount; i++)
    {
        if(monsterArray[i].coord.X == X && monsterArray[i].coord.Y == Y && monsterArray[i].state != 0 )
        {
            monsterindexs[currmapmonstercount]=i;
            currmapmonstercount++;
            if(currmapmonstercount == 9) break;
        }
    }
    //打印怪物
    if(currmapmonstercount == 0)
    {
        printf("当前地图展示还没刷新怪物i");
        return;
    }
    setposition(MARGIN_X+10,INFO_START_Y);
    printf("当前地图出现了如下怪物：");
    setposition(MARGIN_X+10,INFO_START_Y+1);
    for(i = 0; i< currmapmonstercount ; i++ )
    {
        if(i != 0 && i % 3==0)
        {
            setposition(MARGIN_X+10,INFO_START_Y+1+i/3);
        }
        printf("%d.%s(%s）\t",i+1,monsterArray[monsterindexs[i]].name,levelnames[monsterArray[monsterindexs[i]].level-1]);
    }
    setposition(MARGIN_X +5,INFO_END_Y-1);
    int pkmonsterid = -1;
    //monsterid = pkmonsterid;
    do{
        setposition(MARGIN_X +5,INFO_END_Y-1);
        printf("请选择要攻击的对象(按0返回):");
        scanf("%d", &pkmonsterid);
        if(pkmonsterid <= 0 || pkmonsterid > currmapmonstercount){//用户输入错误时清空本行
            setposition(MARGIN_X +5,INFO_END_Y-1);
            printf("                                          ");
        }
    }while(pkmonsterid < 0 || pkmonsterid > currmapmonstercount);
    fight(&monsterArray[monsterindexs[pkmonsterid-1]]);             //用monsterindexs数组来存放当前怪物所在怪物数组的下标
}
void fight(monster *monster)
{
    int fightcount=0;
    // 打架，玩家和怪物互相掉血
    while(1)
    {
        srand(time(NULL));
        // a- b  5-15 %11+5
        //int playerattack = rand()%(21) + 5 ;
        /* 此处有bug，生成随机攻击力的时候，再怪物快死亡时偶尔会使得 monster->hp 这个数值发生未知变化 */
        int playerattack = rand()%(currplayer->Weapon.maxAttack - currplayer->Weapon.minAttack + 1) + currplayer->Weapon.minAttack ;
        monster->hp -= playerattack;
        //monster->hp -= 15;
        if(monster->hp <= 0)
        {
            break;
        }
         if(currplayer->hp <= 0)
        {
            break;
        }

        currplayer->hp -= monster->att;
        setposition(MARGIN_X + 5,INFO_END_Y - 1);
        printf("                                           ");
        setposition(MARGIN_X + 5,INFO_END_Y - 1);
        fightcount++;
        printf("战斗第%d轮：%sHP：%d\t%sHP:%d",fightcount,currplayer->name,currplayer->hp,monster->name,monster->hp);
        usleep(1000 * 200);
    }
            setposition(MARGIN_X+ 5,INFO_END_Y - 1);
            printf("                                           ");
         if(currplayer->hp <= 0)
        {
            setposition(MARGIN_X+ 5,INFO_END_Y - 1);
            printf("                                           ");
            setposition(MARGIN_X+ 5,INFO_END_Y - 1);
            printf("江湖快讯：大侠《%s》在于《%s》的战斗中壮烈牺牲！血量已重置",currplayer->name,monster->name);
            /*  玩家死亡，重置血量 choice是1，2号玩家的血量 */
            if(choice==1)   currplayer->hp=1000;
            if(choice==2)   currplayer->hp=2000;
            return;
        }
        setposition(MARGIN_X+ 5,INFO_END_Y - 1);
        printf("经过艰苦的战斗：《%s》被您杀死，获得%d经验值，%d金币！",monster->name,monster->exp,monster->maxmoney);
        currplayer->exp += monster->exp;
        currplayer->gold += monster->maxmoney;
}
void ShowHQ()
{
    X = currplayer->martial.hqCoord.X;
    Y = currplayer->martial.hqCoord.Y;
    showmap();
}
