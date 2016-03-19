# `make` and `cmake`

* [ref1](http://blog.csdn.net/shaoxiaohu1/article/details/9179715)  
  [ref2](http://my.oschina.net/xunxun/blog/86781)  
  [3.](https://www.daniweb.com/programming/software-development/threads/492795/help-with-understanding-cmake)  
  [4. What is the difference between make and gcc?](http://stackoverflow.com/questions/768373/what-is-the-difference-between-make-and-gcc)  
  

 大家都知道，写程序大体步骤为：
 
 1.用编辑器编写源代码，如.c文件  
 2.用编译器编译代码生成目标文件，如.o   
 3.用链接器连接目标代码生成可执行文件，如.exe  
 
 但如果源文件太多，一个一个编译时就会特别麻烦，于是人们想到，为什么不设计一种类似批处理的程序，来批处理编译源文件呢，于是就有了make工具，它是一个自动化编译工具，你可以使用一条命令实现完全编译。但是你需要编写一个规则文件，make依据它来批处理编译，这个文件就是makefile，所以编写makefile文件也是一个程序员所必备的技能。
 
 对于一个大工程，编写makefile实在是件复杂的事，于是人们又想，为什么不设计一个工具，读入所有源文件之后，自动生成makefile呢，于是就出现了cmake工具，它能够输出各种各样的makefile或者project文件,从而帮助程序员减轻负担。但是随之而来也就是编写cmakelist文件，它是cmake所依据的规则。所以在编程的世界里没有捷径可走，还是要脚踏实地的。

* [由make进化至cmake](http://www.cnblogs.com/liuyangnuts/archive/2013/02/06/2907440.html)