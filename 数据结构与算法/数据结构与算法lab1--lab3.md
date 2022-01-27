

[toc]

# 数据结构与算法lab1-->lab3

> 说明:
>
> - 老师说过:算法设计题不会直接考现成的算法,而是灵活应用,比如:通过求 树的根节点到任意二度节点的最大路径长  来考察dfs(深度搜索);所以像Dijkstra这种,就直接略去了
> - lab4 Dijkstra最短路径算法,在我看来几乎不可能考(因为除非背代码,否则手写出来的代码未经过调试,边界条件十有八九都有问题),故略去
> - 伪代码方面没有统一的规范,所以语言风格可以尽量接近自己熟悉的语言,比如我会尽量贴近java来写,适当简省
>

**张莉老师说了:不考PPT上有的算法设计题,不考出过的题,所以三个lab留个印象就行,其余全靠临场发挥**;

与其复习 实验,我更愿意把:

- 链表(含栈,队列)
- 树(bfs,dfs)
- 图(简单的bfs和dfs)
- 排序

滚熟点,然后尽人事,听天命.

 (以上皆为我个人的看法,入坑了不负责哦(。•ˇ‸•...))



----

---





## 一. lab1 线性表&多项式

1. 实验目的

> Accomplish:
>
> (1) the implementation of **linear list**.
>
> (2) the implementation of **Iterator**
>
> (3) the application of linear list--the implementation of **Polynomial**
>
> (4) test them
>
> 实现线性表(含add,remove),迭代器,多项式



2. 核心代码

- LinkedList域属性

```java
public class LinkedList<E> {
    //头结点的data为空
    private Node<E> head = new Node<E>();
    class Node<E> {
        private E data;
        public Node<E> next;

        public Node(E data) {
            this.data = data;
        }

        public Node(E theData, Node<E> theNext) {
            data = theData;
            next = theNext;
        }
        ......
}
```

- ==addToFront==


```java
/**
 * 头插法
 * @param val 需要插入的数据
 */
public void addToFront(E val) {
    Node<E> cur = new Node<E>(val);
    cur.next = head.next;
    head.next = cur;
}

```

- ==removeFromFront==

```java
public void removeFromFront() throws EmptyListException {
    if (isEmpty()) {
        throw new EmptyListException();
    }
    head.next = head.next.next;
}
```



- Iterator(由于1. 与语言特性有关,2. 未体现算法知识,3. 用伪代码实现毫无意义,所以我认为几乎不可能考)

```java
public class LinkedListItr<E> implements java.util.Iterator<E> {
    private Node<E> currentPosition;

    public LinkedListItr(Node<E> firstNode) {
        currentPosition = firstNode.getNext();
    }

    @Override
    public boolean hasNext() {
        return currentPosition != null;
    }

    @Override
    public E next() {
        E returnedObject = currentPosition.getData();
        currentPosition = currentPosition.getNext();
        return returnedObject;
    }

}

public LinkedListItr<E> getIterator() {
    return new LinkedListItr<>(head);
}
```



-  ==Polynomial==

```java
/**
 * 利用系数和指数数组创建多项式
 *
 * @param coefArray
 * @param expArray
 */
public Polynomial(float[] coefArray, int[] expArray) {
    //在利用数组初始化前,先进行排序,避免为后续add操作带来麻烦
    List<Map.Entry<Integer, Float>> list = polynomialSort(coefArray,expArray);
    if (coefArray.length != expArray.length) {
        throw new IllegalArgumentException();
    }
    for (int i = 0; i < coefArray.length; i++) {
        this.addTerm(new Term(list.get(i).getValue(),list.get(i).getKey()));
    }
}

```

- Polynomial add

```java
/**
 * 计算两个多项式的和
 *
 * @param B
 * @return
 */
public Polynomial add(Polynomial B) {
    Polynomial C = new Polynomial(); // C为结果多项式
    int a = 0; // a为this多项式的当前项索引
    int b = 0;  // b为多项式B的当前项索引
    float coef; //结果多项式当前项系数
    while (a < size() && b < B.size()) {
        Term ta = getTerm(a);
        Term tb = B.getTerm(b);
        if (ta.exp == tb.exp) {
            coef = ta.coef + tb.coef;
            if (coef != 0) {
                C.addTerm(new Term(coef, ta.exp));
            }
            a++;
            b++;
        }

        if (ta.exp < tb.exp) {
            C.addTerm(new Term(tb.coef, tb.exp));
            b++;
        }
        if (ta.exp > tb.exp) {
            C.addTerm(new Term(ta.coef, ta.exp));
            a++;
        }
    }

    for (; a < size(); a++) {
        C.addTerm(new Term(getTerm(a)));
    }
    for (; b < B.size(); b++) {
        C.addTerm(new Term(B.getTerm(b)));
    }
    return C;
}

```

> 说明:
>
> 扫描两个相加多项式，若都未检测完：
> ● 若当前被检测项指数相等，系数相加。
>   若未变成 0，则将结果加到结果多项式。
> ● 若当前被检测项指数不等，将指数⼩者加到结果多项式。 
>
> ●若有⼀个多项式已检测完，将另⼀个多项式剩余部分复制到结果多项式。



- 总结:

> removeFromFront
>
> addToFront
>
> Polynomial add
>
> 三处考察几率较大



---

---

## 二. lab2 停车场模拟

1. 实验目的

   >  Accomplish:
   >
   > (1) the implementation of  ‘Class Car’
   >
   > (2) the implementation of ‘void parkingLotSimulation()’ (‘part’ & ‘depart’ process included)
   >
   > 实现:
   >
   > ‘Class Car’ ,  ‘void parkingLotSimulation()’ (停车场模拟方法,含part&depart)

2. 核心代码

- Class Car

  ```java
  class Car {
      /**
       * licence:牌照,如:'TUE-87B'
       * moveTimes:移动次数
       */
      String licence;
      int moveTimes;
  
      Car(String licence) {
          this.licence = licence;
          this.moveTimes = 0;
      }
  
      String getLicence() {
          return licence;
      }
  
      int getMoveTimes() {
          return moveTimes;
      }
  
      void moveCar() {
          moveTimes++;
      }
  }
  
  ```

- ==Park==

  ```java
  //车辆停入功能的实现
  if ("arrives".equals(array[1])) {//在原题情景中,array[1]存放"arrives"or"dapart"字符,array[0]存放拍照,如licence:牌照,如:'TUE-87B'
      count++;
  
      //最大停车数为5，超过则拒绝停入
      if (count > maxNumber) {
          System.out.println("Sorry " + array[0] + ", the lot is full");
          count--;
          continue;
      }
      Car newCar = new Car(array[0]);
  
      //车停入
      stack1.push(newCar);
  }
  ```

  > 关键:if (count > maxNumber) 判断栈是否已满,如果已满,该车Part请求将被忽略

  

- ==Depart==

  ```java
  //车辆开出功能的实现
  
  //Stack2用来存放暂时挪出停车场的车辆
  Stack<Car> stack2 = new Stack<>();
  
  //若栈顶的车辆不是要出去的车辆，则将出去车辆前的所有车辆移出并存入stack2
  if ("departs".equals(array[1])) {
      try {
          while (!stack1.peek().getLicence().equals(array[0])) {
              stack1.peek().moveCar();
              stack2.push(stack1.peek());
              stack1.pop();
          }
          if (stack1.peek().getLicence().equals(array[0])) {
              System.out.println(stack1.peek().getLicence() + " was moved " + stack1.peek().getMoveTimes() + " times while it was here");
              stack1.pop();
              count--;
              while (!stack2.empty()) {
                  //待要出去的车辆移出后,还要将stack2暂存的车辆再重新移入停车场(即stack1)
                  stack1.push(stack2.peek());
                  stack2.pop();
              }
          }
      }catch (Exception e){
          System.out.println("Illegal input file!");
      };
  }
  ```

  > 关键:
  >
  > 待要出去的车辆移出后,还要将stack2暂存的车辆再重新移入停车场(即stack1)
  
- 总结:

  > 可能由 栈来实现情景模拟,实现表达式字符匹配,来考察栈的知识,所以lab2具有一定参考价值

  > 打印机那道题没写,欢迎补充



## 三. lab3:BST,二叉搜索树

- Implementing Binary Search Trees Using Arrays

  ```java
  public class BinarySearchTree<E extends Comparable> {
      private Node<E>[] nodes;
      private int root = -1;
      private int firstFree = 0;
  
      public BinarySearchTree() {
          nodes = new Node[10];
      }
      ...
  }
  ```

  

- ==Insert==

  ```java
      public void insert(E data) {
          int index;
          //firstFree是arrayd第一个可插入空间
          if (firstFree + 1 > nodes.length) {
              expand();//如果array内存不足,则拓容
          }
  
          nodes[firstFree] = new Node(data);
  
          Node<E> currentNode;
          //如果为根节点
          if (root == -1) {
              root = firstFree;
              firstFree++;
          } else {
              int parent;
              int current = root;
              while (true) {
                  parent = current;
                  currentNode = nodes[current];
                  //如果插入数值小于currentNode.getData(),且currentNode右节点为空,则把firstFree设为...的右节点
                  if (currentNode.getData().compareTo(data) < 0) {
                      current = currentNode.getRight();
                      if (current == -1) {
                          nodes[parent].setRight(firstFree);
                          firstFree++;
                          return;
                      }
                  } else
                  {
                      current = currentNode.getLeft();
                      if (current == -1) {
                          nodes[parent].setLeft(firstFree);
                          firstFree++;
                          return;
                      }
                  }
              }
          }
      }
  
  ```

  

- remove

  三种情况,过于复杂,顶多考简答题,要求画出remove后的BST,不大可能考算法设计题

  > - 1. 要删除节点有**零个孩子**，即叶子节点
  >
  > ![img](https://img2018.cnblogs.com/blog/1459179/201905/1459179-20190506103928855-819858787.png)
  >
  > 如图所示，只需要将parent.left(或者是parent.right)设置为null，然后Java垃圾自动回收机制会自动删除current节点。
  >
  > - 2. 要删除节点有**一个孩子**
  >
  > ![img](https://img2018.cnblogs.com/blog/1459179/201905/1459179-20190506104753788-110670825.png)
  >
  > 如图所示，只需要将parent.left(或者是parent.right)设置为curren.right(或者是current.left)即可。
  >
  > ![img](https://img2018.cnblogs.com/blog/1459179/201905/1459179-20190506120347390-190050418.gif)
  >
  > - 3. 要删除节点有**两个孩子**
  >
  > 这种情况比较复杂，首先我们引入**后继节点**的概念，如果将一棵二叉树按照中序周游的方式输出，则任一节点的下一个节点就是该节点的后继节点。例如：上图中24的后继节点为25，64的后继节点为70.找到后继节点以后，问题就变得简单了，分为两种情况：
  >
  > 3.1.**后继节点为待删除节点的右子**，只需要将curren用successor替换即可，注意处理好current.left和successor.right.
  >
  > 注意：这种情况下，successor一定没有左孩子，一但它有左孩子，哪它必然不是current的后继节点。
  >
  > ![img](https://img2018.cnblogs.com/blog/1459179/201905/1459179-20190506130426071-932016809.png)
  >
  > ![img](https://img2018.cnblogs.com/blog/1459179/201905/1459179-20190506131013574-818545202.gif)
  >
  > 3.2.**后继节点为待删除结点的右孩子的左子树**，这种情况稍微复杂点，请看动态图片演示。
  >
  > ![img](https://img2018.cnblogs.com/blog/1459179/201905/1459179-20190506131255284-111280623.png)
  >
  > ![img](https://img2018.cnblogs.com/blog/1459179/201905/1459179-20190506131635368-1781502271.gif)
  >
  > 算法的步骤是：
  >
  > 1. successorParent.left=successor.right
  > 2. successor.left=current.left
  > 3. parent.left=seccessor

  - [参考](https://www.cnblogs.com/yahuian/p/10813614.html)
  - [remove的可视化网站](https://visualgo.net/zh/bst)

  

- Compactification(紧凑化,即:解决 remove后产生的hole 带来的 空间浪费)

> 思路:在remove的基础上, 在每次remove成功后追加方法**void fillHole(int hole,int parent,boolean isRightChild);**
>
> ```java
> /**
>  * 填洞操作
>  */
> public void fillHole(int hole,int parent,boolean isRightChild){
>     //移动最后一个元素到洞中
>     nodes[hole] = nodes[--firstFree];
> 
>     //更改被移动元素的父节点的左指针或右指针
>     if(parent!=-1){
>         if(isRightChild){
>             nodes[parent].setRight(hole);
>         }else {
>             nodes[parent].setLeft(hole);
>         }
>     }else {//被删除元素若为根节点,那在remove中,root被置为了新值,引入填hole机制后,需要变回旧值
>         root=hole;
>     }
> 
> ```
>
> 可remove都不太可能考,更别提Compactification了





