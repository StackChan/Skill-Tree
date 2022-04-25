

---

# 语言知识

### vue

> Vue总结:
>
> > **个人总结：**(先看:[vue中文件的引用关系](https://www.cnblogs.com/smile-fanyin/p/11258300.html))
> >
> > 深入:[[关于Vue中main.js，App.vue，index.html之间关系进行总结](https://www.cnblogs.com/chenleideblog/p/10484554.html)](https://www.cnblogs.com/chenleideblog/p/10484554.html)
> >
> > 　　**1、html文件中基本不写什么东西，只是写一个组件标签。**
> >
> > 　　**2、入口的main.js文件引入vue框架 和 App.vue主组件，然后实例化vue对象，在components属性中定义组件名（把引入App.vue主组件定义一个名字，返给html文件运用）**
> >
> > 　　**3、App.vue主组件，里面集合了html、js、css语法，在此主组件文件中，也可以引用其他子组件，引用时在script标签所在的js中，用import引入，然后在实例化vue对象中的components中定义名字，然后在template所在的html中运用。**
> >
> > 　　**4、子组件在components文件中，一般此文件夹中放置的都是子组件，被App.vue主组件引用。**
> >
> > 实际上,实现复杂页面布局并不简单,所以大家一般都从网上找到相关布局的模板进行修改!
> >
> > baidu.com 搜索 **前端开发页面模板**
> >
> > [**36个炫酷前端页面模板**](https://download.csdn.net/download/qingchunjian/8373257)
> >
> > [gitee 前端&后台模板](https://gitee.com/A_YuanZ/frontend_page_template)
> >
> > JavaServer Faces (JSF)  插件  组件开发模式
> >
> > JSF 还通过将良好构建的模型-视图-控制器 (MVC) 设计模式集成到它的体系结构中，确保了应用程序具有更高的可维护性。
> >
> > [vue模板网站(微付费即可使用,不过几块钱)](http://www.bootstrapmb.com/tag/vuemoban)
> >
> > 上面这些资源,实际上,都不需要看,都不重要,因为有免费开源的且极美的:[[22种开源Vue模板和主题框架「干货」](https://www.cnblogs.com/cczlovexw/p/13267709.html)](https://www.cnblogs.com/cczlovexw/p/13267709.html)











# 暑假实训备选模板:





gitee意象商城项目:

[guchengwuyue](https://gitee.com/guchengwuyue) / [yshop意象商城系统](https://gitee.com/guchengwuyue/yshopmall)



**总结:** 为暑假实训提供的一个可行性很强的方案:

> [[22种开源Vue模板和主题框架「干货」](https://www.cnblogs.com/cczlovexw/p/13267709.html)](https://www.cnblogs.com/cczlovexw/p/13267709.html)
>
> 其中瞩目的几个模板(非框架,那几个框架,说白了,什么都没有)
>
> 基于这两个项目直接进行融合&更改即可
>
> 人人开源 / renren-fast-vue
>
> vue & nuxt 博客网站
>
> RuoYi-Vue
>
> **他们都有说明运行方法&配置方法,人人开源/RuoYi-Vue 更是说明文档更是丰富到不行**
>
> 是暑期实训的绝对第一选择!





---



### **sql:**

 **CURD**(执行查询、获取数据、插入新的记录、删除记录以及更新记录)

通过 SQL 创建数据库、表、索引，以及如何撤销它们。

我们已经学习了 SQL 中最重要的 Aggregate 函数。

SQL 是一种与**数据库系统(DBS)协同工作的标准语言**，这些数据库系统包括 **MS SQL Server**、IBM DB2、Oracle、**MySQL (最广泛)和 MS Access(windows,小型网站)** 等等。

[SQL快速参考](https://www.runoob.com/sql/sql-quickref.html)



```mysql
# num() not sum()
SELECT * from (SELECT (emp_no,count(emp_no) ) as new from salaries group by emp_no) 
where new.emp_no>15
```



```
SQL_ERROR_INFO: 'Every derived table must have its own alias'
```



```
标准的SQL 的解析顺序为: (1).FROM 子句 组装来自不同数据源的数据 （包括JOIN）(2).WHERE 子句 基于指定的条件对记录进行筛选 (3).GROUP BY 子句 将数据划分为多个分组 (4).使用聚合函数进行计算 (5).使用HAVING子句筛选分组 (6).计算所有的表达式 (7).使用ORDER BY对结果集进行排序
https://blog.csdn.net/a1669380588/article/details/101419404
举例说明: 在学生成绩表中 (暂记为 tb_Grade), 把 "考生姓名"内容不为空的记录按照 "考生姓名" 分组, 并且筛选分组结果, 选出 "总成绩" 大于 600 分的.
标准顺序的 SQL 语句为:
select 考生姓名, max(总成绩) as max总成绩
from tb_Grade
where 考生姓名 is not null
group by 考生姓名
having max(总成绩) > 600
order by max总成绩

在上面的示例中 SQL 语句的执行顺序如下:
(1). 首先执行 FROM 子句, 从 tb_Grade 表组装数据源的数据(JOIN included)
(2). 执行 WHERE 子句, 筛选 tb_Grade 表中所有数据不为 NULL 的数据
(3). 执行 GROUP BY 子句, 把 tb_Grade 表按 "学生姓名" 列进行分组
(4). 计算 max() 聚集函数, 按 "总成绩" 求出总成绩中最大的一些数值
(5). 执行 HAVING 子句, 筛选课程的总成绩大于 600 分的.
(7). 执行 ORDER BY 子句, 把最后的结果按 "Max 成绩" 进行排序.
```

==示例:==

```mysql
select name,max(grade) as maxGrade
from table1
left join table2
on table1.name=table2.name
where name is not null
group by name
having maxGrade>600
order by maxGrade
```



一个细节:

```
SELECT em.emp_no,ma.emp_no FROM
dept_emp as em,dept_manager as ma
```

结果很神奇,循环嵌套!对 select from的理解更深了!     





**group by 关键字聚合中select非聚合列的结果:**


```mysql
select de.emp_no,de.dept_no,max(sa.salary) as maxSalary
from dept_emp as de left join salaries as sa
on de.emp_no=sa.emp_no
group by de.dept_no
order by de.dept_no asc
```

报错:

```
SQL_ERROR_INFO: "Expression #1 of SELECT list is not in GROUP BY clause and contains nonaggregated column 'de.emp_no' which is not functionally dependent on columns in GROUP BY clause; this is incompatible with sql_mode=only_full_group_by"
```

原因:group by聚合时,只能select聚合元素de.dept_no与聚合函数,不能聚合 非聚合列:dept_no(**sqlite此时会选择聚合进任意一个值,mysql则不能通过,更安全**)

> 事实上,**为什么dept_name 不属于聚合键，依然可以直接多表连接。**
> 根据我查找的资料官方解释是：**当group by 后面跟上主键或者不为空唯一索引时，查询是有效的，因为此时的每一笔数据都具有唯一性。**

```mysql
select de.dept_no,max(sa.salary) as maxSalary
from dept_emp as de left join salaries as sa
on de.emp_no=sa.emp_no
group by de.dept_no
order by de.dept_no asc
```



[SQL12 **获取每个部门中当前员工薪水最高的相关信息**](https://www.nowcoder.com/practice/4a052e3e1df5435880d4353eb18a91c6?tpId=82&tags=&title=&difficulty=&judgeStatus=&rp=1&gioEnter=menu)









- 多个JOIN从左到右执行
- `select * from a left join b on a.id=b.id left join c on b.id=c.id` 先a和b交的结果集t，t再和c相交







**A inner join B** 取交集。

**A left join B** 取 A 全部，B 没有对应的值为 null。

**A right join B** 取 B 全部 A 没有对应的值为 null。

**A full outer join B** 取并集，彼此没有对应的值为 null。

对应条件在 **on** 后面填写。

```
UNION 操作符用于合并两个或多个 SELECT 语句的结果集。

请注意，UNION 内部的每个 SELECT 语句必须拥有相同数量的列。列也必须拥有相似的数据类型。同时，每个 SELECT 语句中的列的顺序必须相同。

SELECT column_name(s) FROM table1
UNION
SELECT column_name(s) FROM table2;
```





---

### **HTML:**



```
以下层层深入：

了解基本的 HTML 标签种类（包括 HTML5 的新标签），常用标签的特性和属性；
常用的布局方式（Div, Table, etc.），标签样式的继承原理；
DOM tree 的原理，事件传递机制（event bubbling & propagation）；
浏览器的网页渲染原理，DOCTYPE 对渲染模式的影响，页面 repaint & reflow 机制等；
在这个过程中，你的 CSS 和 JavaScript 功力也会随之长进，你也会逐渐明白 HTML 是如何与 CSS、JavaScript、浏览器通信等模块相衔接的。
```



### **JS:**

[js中的var&let&const](https://www.runoob.com/js/js-let-const.html)

> ES2015(ES6) 新增加了两个重要的 JavaScript 关键字: **let** 和 **const**;注意**let**关键字的重要作用,记住:没有let,那var只有全局作用于和函数局部作用域,没有块作用域(含循环体作用域)
>
> 且全局变量中:
>
> - let carName不能使用 window.carName访问(不属于window对象)  
> - var carName能使用 window.carName访问(属于window对象)
>
> 且js只支持var变量被var变量重新声明:
>
> **var x =2;var x =3;**
>
> - var x = 2;  // x 为 2  var x = 3;  // 现在 x 为 3
> - var x=2; let x 3;//不合法
> - let x =2;let x=3;//不合法
> - let x=2;var 3//不合法
>
> 且var支持**变量提升**,let不支持,即var 关键字定义的变量可以在使用后声明





> 如果您把值赋给尚未声明的变量，该变量将**被自动作为 window 的一个属性。**
>
> 这条语句：
>
> carname="Volvo";
>
> 将声明 window 的一个属性 carname。
>
> 非严格模式下给未声明变量赋值创建的全局变量，是全局对象的**可配置属性，可以删除**。
>
> ```
> var var1 = 1; // 不可配置全局属性
> var2 = 2; // 没有使用 var 声明，可配置全局属性
> 
> console.log(this.var1); // 1
> console.log(window.var1); // 1
> console.log(window.var2); // 2
> 
> delete var1; // false 无法删除
> console.log(var1); //1
> 
> delete var2; 
> console.log(delete var2); // true
> console.log(var2); // 已经删除 报错变量未定义
> ```



**HTML事件实例**

> - HTML 页面完成加载 -->document.write("xxxx");被触发
> - HTML input 字段改变时  -->
> - HTML 按钮被点击 --> <button onclick="getElementById('demo').innerHTML=Date()">现在的时间是?</button>onclick事件被触发





**===表示绝对相等(数据类型&值)**

> var x = "John";       
> var y = new String("John");
> (x === y) // 结果为 false，因为 x 是字符串，y 是对象
>
> >  不要创建 String 对象。它会拖慢执行速度，并可能产生其他副作用





**JavaScript 数据类型**

> **最重要:** 
>
> typeof "John"         // 返回 string
> typeof 3.14          // 返回 number
> typeof NaN           // 返回 number
> typeof false         // 返回 boolean
> typeof [1,2,3,4]       // 返回 object
> typeof {name:'John', age:34} // 返回 object
> typeof new Date()       // 返回 object
> typeof function () {}     // 返回 function
> typeof myCar         // 返回 undefined (如果 myCar 没有声明)
> typeof null          // 返回 object
>
> 如果对象是 JavaScript Array 或 JavaScript Date ，我们就无法通过 **typeof** 来判断他们的类型，因为**都是 返回 object。**

> 不重要:(重点是上面那些例子)
>
> 在 JavaScript 中有 6 种不同的数据类型：(如:var s="John";string类型)
>
> - string
> - number
> - boolean
> - object
> - function
> - symbol
>
> 3 种对象类型：(如var o=new String("John");Object类型)
>
> - Object
> - Date
> - Array
>
> 2 个不包含任何值的数据类型：
>
> - null
> - undefined



**constructor** 属性返回所有 JavaScript 变量的构造函数。

> "John".constructor         // 返回函数 String() { [native code] }
> (3.14).constructor         // 返回函数 Number() { [native code] }
> false.constructor         // 返回函数 Boolean() { [native code] }
> [1,2,3,4].constructor       // 返回函数 Array()  { [native code] }
> {name:'John', age:34}.constructor // 返回函数 Object() { [native code] }
> new Date().constructor       // 返回函数 Date()  { [native code] }
> function () {}.constructor     // 返回函数 Function(){ [native code] }



**正则表达式**

> 正则表达式是由**一个字符序列**形成的搜索模式(pattern,SQL为使用LIKE关键字匹配pattern)。
>
> 当你在文本中搜索数据时，你可以用搜索模式来描述你要查询的内容。
>
> 正则表达式可以是一个简单的字符，或一个更复杂的模式。
>
> 正则表达式可用于所有**文本搜索和文本替换**的操作。
>
> eg. /e/.test("The best things in life are free!");
>
> 详见:https://www.runoob.com/js/js-regexp.html
>
> 其中  RegExp 的使用较复杂,可详细看!
>
> ```
> ^+$分别表示：1、^：匹配输入字符串的开始位置。2、+：匹配前面的子表达式一次或多次（大于等于1次）。3、$：匹配输入字符串的结束位置。正则表达式，又称规则表达式。
> [正则表达式示例](https://www.cnblogs.com/s593941/p/9493425.html)
> ```
>
> 



-----

# 散

**通过eNSP实验:**

交换机

host1:192.168.2.3  dns:255.255.0.0  gateway:192.168.1.1  **request timeout!**

![image-20220305151634827](数据库(SQL)+Vue网页实战.assets/image-20220305151634827.png)

host2: 192.168.1.2  255.255.255.0  gateway:192.168.1.1 Destination host unreachable

![image-20220305151637816](数据库(SQL)+Vue网页实战.assets/image-20220305151637816.png)

我们修改host1:host:192.168.1.2 dns:255.255.255.0 gateway:192.168.1.4,如此,只有网关原因可能会造成不能ping通;证明:需要host在同一网段(由dns决定),也需要网关相同

![image-20220305153202304](数据库(SQL)+Vue网页实战.assets/image-20220305153202304.png)

----



**通过VirtualBox实验:**(虚拟机开启桥接模式(需要重启),会自动分配ip,分配了172.22.27.111) broadcast 172.22.255.255

![image-20220305152327256](数据库(SQL)+Vue网页实战.assets/image-20220305152327256.png)

本地PC:  gateway:172.22.255.254(图就不截进来了)

![image-20220305152410621](数据库(SQL)+Vue网页实战.assets/image-20220305152410621.png)

 本地网路连接:

![image-20220305152459903](数据库(SQL)+Vue网页实战.assets/image-20220305152459903.png)

桥接模式下,PC&Ubuntu能互相ping通

![image-20220305152234566](数据库(SQL)+Vue网页实战.assets/image-20220305152234566.png)

(host-only仅主机模式中,由于virtualbox反复删除导致其失去了对virtual-box host-only network(PC端ip:192.168.56.1)的控制权,所以略有小错误;当然,在setting中设置ip为192.168.56.2,gateway:192.168.56.1 此时能实现host-only效果:能ping通 192.168.56.1 PC能ping通虚拟机 不能访问外网)  ;但PC开WLAN共享网络给virtual-box host-only network,此时192.168.56.1--自动-->192.168.137.1--我可以手动改回-->192.168.56.1,则ping 192.168.56.1不成功)



交换机通过不同端口连接计算机组成局域网

MAC地址6个字节:前三:厂商表示 后三:厂商自行赋予的拓展标识(2^24^)

基于交换机的局域网,直接配置在相同网段连接交换机就可互相通信



路由器:路由转发,实现两个局域网之间的通信

工作原理:基于路由表(动态路由表&静态路由表)









