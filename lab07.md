<h1 style="text-align:center;color:#0080FF;font-weight:bold;font-size:40px">PIPPIN实验报告</h1>
<p style="color:black;">18340128 罗濠铭</p>
<p style="font-size:23px;color:black;">实验目的</p>
<ul style="color:black">
    <li>理解冯·诺伊曼计算机的结构
    <li>理解机器指令的构成
    <li>理解机器指令执行周期
    <li>用汇编编写简单程序
</ul>
<div><h2 style="text-align:center;">task 1</h2>
<p style="font-size:20px;color:#FF9D6F">PROGRAM 1 流程</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">首先，输入代码</p>
<img src="images/lab7.11.png">
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">然候运行程序</p>
<img src="images/lab7.1.png">
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">运行结果</p>
<img src="images/lab7.21.png">
<p style="font-size:20px;color:#FF9D6F">PC,IR寄存器的作用</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">PC寄存器用來計数下一个指令的地址</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">IR寄存器用來加载指令</p>
<p style="font-size:20px;color:#FF9D6F">ACC寄存器的全称与作用</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">ACC:Accumulator（累加器）,用来储存CPU计算时产生的中间结果,这样就可以省去计算过程要把数据写入内存所需的时间</p>
<p style="font-size:20px;color:#FF9D6F">LOD #3指令的Fetch-Execute cycle</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">首先，IR寄存器加载到LOD #3指令，并且传到Decoder去解码这条指令</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">然后,ALU根据Decoder传来的指令来判断运算操作符(此时为=)，因为指令是LOD，所以不用从ACC获得数据，接着MUX(数据选择器)根据Decoder传来的指令切换模式获取数据(immidiate mode)，最后由ALU执行运算操作</p>
<img src="images/lab7.1.png">
<p style="font-size:20px;color:#FF9D6F">ADD W指令的Fetch-Execute cycle</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">IR寄存器加载ADD W指令，并且传到Decoder去解码这条指令</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">然后，ALU根据Decoder传来得指令来将操作符变为+，因为指令是ADD，所以要从ACC那里获得一个值，接着MUX根据Decoder传来的指令切换模式(Direct Addressing mode)到指定内存(W)获得值，最后由ALU执行运算操作符</p>
<img src="images/lab7.2.png">
<p style="font-size:20px;color:#FF9D6F">LOD #3 与 ADD W指令在Fetch-Execute有什么不同?</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">LOD #3 不用从ACC那里获取值作运算，ADD W 要从ACC获取值、LOD #3 不需要从内存获取值，ADD W 要从内存获取值</p>
</div>

<div><p style="font-size:20px;color:#FF9D6F">Binary</p>
<img src="images/lab7.3.png">
<p style="font-size:20px;color:#BE77FF;padding-left:25px;">LOD #7 00010100 00000111</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">前面00010100的前3个bit为无意义，第四个bit指要什么模式取值，0为从内存取，1为直接的值，后面4个bits为运算操作的模式0100为LOD，后面00000111为值或者内存地址。</p>
<p style="font-size:20px;color:#BE77FF;padding-left:25px;">RAM Address</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">在指令区RAM每个指令占了2个btyes，而数据区每个地址占1个btye</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">该机器CPU是8位</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">C代码的表示</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">int8_t a = 3;</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">int8_t b = 7;</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">int8_t c = a + b;</p>
</div>

<div><h2 style="text-align:center;">task 2</h2>
<p style="font-size:20px;color:#FF9D6F">PROGRAM 2的流程</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">首先，输入代码</p>
<img src="images/lab7.31.png">
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">然候运行到最后</p>
<img src="images/lab7.5.png">
<p style="font-size:20px;color:#FF9D6F">Program 2程序的作用</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">将一个变量值减到1为止</p>
<img src="images/lab7.5.png">
<p style="font-size:20px;color:#FF9D6F">对应C的程序</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">int8_t a = 3;</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">for(a;a>1;a--){}</p>
<p style="font-size:20px;color:#FF9D6F">修改程序，用机器语言实现10+9+8+...+1，并把结果放到内存Y</p>
<p style="font-size:20px;color:#FF9D6F">写出C语言的计算过程</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">int8_t sum = 0;</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">int8_t a = 10;</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">for(a;a>1;a--)
{ sum = sum + a;
}
</p>
<p style="font-size:20px;color:#FF9D6F">写出机器语言的计算过程</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">LOD X</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">ADD Y</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">STO Y</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">LOD X</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">SUB #1</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">JMZ 16</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">STO X</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">JMP 0</p>
<p style="font-size:18px;color:#BE77FF;padding-left:25px;">HLT</p>
<img src="images/lab7.4.png">

<p style="font-size:20px;color:#FF9D6F">总结高级语言与机器语言的区别与联系</p>
<p style="font-size:18px;color:black;padding-left:25px;">我感觉高级语言比较有逻辑可言，易读性高，所以很容易修BUG。相反，机器语言比较有深入性，能真正知道计算机在这个程序里面的操作，但可读性低，难修BUG。</p>
<p style="font-size:18px;color:black;padding-left:25px;">它们之间会有一个对应的表来对应两边的每条指令来将高级语言编译成机器语言</p>

<p style="font-size:20px;color:#FF9D6F">实验小结</p>
<p style="font-size:18px;color:black;padding-left:25px;">这次的实验目标顺利的达成了，通过这次实验的完成，我学到了CPU怎么在运作，更加的巩固我对CPU的了解，谢谢。</p>
</div>
