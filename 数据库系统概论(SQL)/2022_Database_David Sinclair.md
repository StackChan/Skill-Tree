之前的基础:

搜索:个人平台运行项目.md 能找到上次所做尝试的笔记

已经安装mysql 遵循的安装教程:[mysql安装教程](https://www.cnblogs.com/laumians-notes/p/9069498.html)

密码:123456 非root

idea已经能连接数据库并在console进行直接的操控!

Datagrip(专业的工具,也已经安装)

[陈宋贤分享的mysql速成笔记](https://note.youdao.com/ynoteshare/mobile.html?id=0f5825c8ee759c1eb14f21bff733ea88&type=note&_time=1649159867345#/)



```
mysql> select user,host,authentication_string from mysql.user
    -> ;
+------------------+-----------+------------------------------------------------------------------------+
| user             | host      | authentication_string                                                  |
+------------------+-----------+------------------------------------------------------------------------+
| mysql.infoschema | localhost | $A$005$THISISACOMBINATIONOFINVALIDSALTANDPASSWORDTHATMUSTNEVERBRBEUSED |
| mysql.session    | localhost | $A$005$THISISACOMBINATIONOFINVALIDSALTANDPASSWORDTHATMUSTNEVERBRBEUSED |
| mysql.sys        | localhost | $A$005$THISISACOMBINATIONOFINVALIDSALTANDPASSWORDTHATMUSTNEVERBRBEUSED |
| root             | localhost | *6BB4837EB74329105EE4568DDA7DC67ED2CA2AD9                              |
```

管理员root的host是localhost，代表仅限localhost登录访问。如果要允许开放其他ip登录，则需要添加新的host。如果要允许所有ip访问，可以直接修改成“**%**”

　　在MySQL中,schema和database是同义词.

CREATE SCHEMA和CREATE DATABASE是等效的.

但是其他的数据库产品(几乎所有数据库)有所不同.在oracle数据库产品中,schema是database的一部分.

表示the tables and other objects owned by a single user.

(database:仓库,schema:仓库里的房间,table:床位,床位上能放各种东西,如行如列,table是数据库存储的基本单位)

我暂时的常用指令:

首先登录:

```
 //cd D:\mysql-8.0.26-winx64,我已经设置了环境变量,所以不需要了!
 mysql -uroot -p
 //输入123456我的密码
 show databases//查看所有database,不过在MySql汇总,database与schama是同义词
 use lab//使用老师创建的lab schema(我已经运行过了!)
 show


```



----





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



