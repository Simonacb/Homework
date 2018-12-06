<style>
@-webkit-keyframes h2{
    0% {color:black;text-shadow:1px 1px 5px black;}
    50% {color:#EEEEEE;text-shadow:none;}
    100% {color:black;text-shadow:1px 1px 5px black;}
}
@keyframes h2{
    0% {color:black;text-shadow:1px 1px 5px black;}
    50% {color:#EEEEEE;text-shadow:none;}
    100% {color:black;text-shadow:1px 1px 5px black;}
}
#anime {
    -webkit-animation-iteration-count:infinite;
    -webkit-animation-duration: 4s;
    -webkit-animation-name:h2;
    animation-duration:4s;
    animation-iteration-count:infinite;
    animation-name:h2;
}
.hello {
    font-size:20px;
    color:black;
}
.hello2{
    font-size:20px;
    color:black;
    text-align:center;
}
.title{
    font-size:28px;
    color:#FFCCFF;
    text-align:center;
}
</style>

<h2 id="anime" style="text-align:center;font-size:30px;">使用Construct 2开发游戏</h2>

<h3 class="hello">根据不久以前我已经介绍过Contruct 2的心得</h3>

[初用Construct2的心得](lab02)

<h3 class="hello">现在，我搞了一个基于迷宫而开发的游戏</h3>

<h2 class="title">拯救公主</h2>

<h3 style="text-align:center;font-size:22px;color:black;">策划游戏的思想</h3>
<h3 class="hello">在一个青青的草原上，公主与王子快乐的生活在一起。本来可以就这样good end完结拍手，可是在某一天，有一只怪物绑架了公主，于是，王子就要深入敌阵去拯救公主</h3>
<h3 class="hello2">开始的想法有以下的元素</h3>
<ol style="font-size:17px;">
    <li>Player:王子</li>
    <li>Boss:怪物</li>
    <li>item:公主</li>
</ol>
<h3 class="hello2">对象的CRC卡片</h3>

<table style="text-align:center;">
<tr>
<th colspan="3">公主</th>
</tr>
<tr>
<td>Attributes</td>
<td>图片</td>
<td>位置</td>
</tr>
<tr>
<td>Collaborator</td>
<td colspan="2">精灵</td>
</tr>
<tr>
<td>Events & Actions</td>
<td colspan="2">销毁自己</td>
</tr>
</table>

<table style="text-align:center;">
<tr>
<th colspan="4">怪物</th>
</tr>
<tr>
<td>Attributes</td>
<td>图片</td>
<td>位置</td>
<td>走动</td>
</tr>
<tr>
<td>Collaborator</td>
<td colspan="3">精灵</td>
</tr>
<tr>
<td>Events & Actions</td>
<td colspan="3">碰撞</td>
</tr>
</table>

<table style="text-align:center;">
<tr>
<th colspan="4">王子</th>
</tr>
<tr>
<td>Attributes</td>
<td>图片</td>
<td>位置</td>
<td>走动</td>
<td>物品(判断有没有救公主)</td>
</tr>
<tr>
<td>Collaborator</td>
<td colspan="4">精灵</td>
</tr>
<tr>
<td>Events & Actions</td>
<td colspan="2">碰撞</td>
<td colspan="2">销毁自己</td>
</tr>
</table>

<table style="text-align:center;">
<tr>
<th colspan="3">墙</th>
</tr>
<tr>
<td>Attributes</td>
<td>图片</td>
<td>位置</td>
</tr>
<tr>
<td>Collaborator</td>
<td colspan="2">精灵</td>
</tr>
<tr>
<td>Events & Actions</td>
<td colspan="2">限制王子越界</td>
</tr>
</table>

<table style="text-align:center;">
<tr>
<th colspan="3">终点</th>
</tr>
<tr>
<td>Attributes</td>
<td>图片</td>
<td>位置</td>
</tr>
<tr>
<td>Collaborator</td>
<td colspan="2">精灵</td>
</tr>
<tr>
<td>Events & Actions</td>
<td colspan="2">碰撞</td>
</tr>
</table>

<table style="text-align:center;">
<tr>
<th colspan="3">赢的图标</th>
</tr>
<tr>
<td>Attributes</td>
<td>图片</td>
<td>位置</td>
</tr>
<tr>
<td>Collaborator</td>
<td colspan="2">精灵</td>
</tr>
<tr>
<td>Events & Actions</td>
<td>判断屏幕位置</td>
<td>设置透明度</td>
</tr>
</table>

<table style="text-align:center;">
<tr>
<th colspan="3">输的图标</th>
</tr>
<tr>
<td>Attributes</td>
<td>图片</td>
<td>位置</td>
</tr>
<tr>
<td>Collaborator</td>
<td colspan="2">精灵</td>
</tr>
<tr>
<td>Events & Actions</td>
<td>判断屏幕位置</td>
<td>设置透明度</td>
</tr>
</table>

<h3 class="hello2">游戏展示</h3>
<h3 class="hello">尝试救公主(由于技术的原因，将公主用星星代替。。。</h3>
<img src="images/game1.gif">

<h3 class="hello">被怪物抓包的情况</h3>
<img src="images/game2.gif">

<h3 class="hello2" style="text-align:center;">游戏设计时的思路</h3>
<h3 class="hello">最开始的时候有很多的想法，例如获得道具来打倒怪物，然后可以把怪物连续生成来让王子去打，又或者是在墙里面发射暗物来让游戏的刺激度更高等等。</h3>
<h3 class="hello">可是鉴于能力和时间的问题，我就只把最最最基础的东西实现出来。</h3>
<h3 class="hello">先把需要的图弄好，例如(王子、公主、怪物、终点的图和迷宫)，这就是背景的设计吧。</h3>
<h3 class="hello">然后，让玩家能操作王子，让怪物能慢慢的走，让公主随机的放在迷宫里，墙要限制王子的越位，还有把终点配置好，这就是游戏的位置操作吧。</h3>
<h3 class="hello">最后，把那些标誌(赢、输)填上，就完成了基本的东西</h3>

<h3 class="hello2">反思</h3>
<h3 class="hello">这个游戏基本的创作我还有两个问题没搞到，就是随机把公主放到迷宫里和墙限制王子的越位，前者有时间的话应该可以实现，后者的话基于我画迷宫的时候把墙画了，导致不能直接在游戏写好的功能上配置，可能我需要把单独的墙画好，慢慢的拼图，将墙配置功能这样子把</h3>

<h3 class="hello2">创作游戏的感想</h3>
<h3 class="hello">平常玩的游戏，看上去好像挺容易搞的出来，但是实际创作小小小游戏后发现有好多逻辑在里面，还有图片那些设计的元素，也要有吸引玩家的意欲的玩法，太辛苦了，真的要向游戏设计和工程的人致敬。</h3> 





