<h2><a href="https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card">Vertical Tree Traversal</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.<br>If there are multiple nodes passing through a vertical line, then they should be printed as they appear in <strong>level order</strong> traversal of the tree.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
</span><span style="font-size: 18px;"><strong>Output: </strong>[4, 2, 1, 5, 6, 3, 8, 7, 9] 
<strong>Explanation:</strong></span>
<img src="https://media.geeksforgeeks.org/img-practice/ScreenShot2021-05-28at3-1622541589.png" alt="">
</pre>
<pre><span style="font-size: 18px;"><strong>Input:
&nbsp;      </strong>1
 &nbsp; &nbsp;/&nbsp;&nbsp;&nbsp; \
 &nbsp; 2&nbsp; &nbsp; &nbsp;  3
 /&nbsp;&nbsp;  \&nbsp; &nbsp; &nbsp;&nbsp;\
4&nbsp; &nbsp;  &nbsp;5&nbsp; &nbsp;  &nbsp;6
<strong>Output: </strong>[4, 2, 1, 5, 3, 6]</span></pre>
<p><strong style="font-size: 18px;">Input:</strong></p>
<pre><span style="font-size: 18px;">       7
 &nbsp; &nbsp;/&nbsp;&nbsp;&nbsp; \
 &nbsp; 2&nbsp; &nbsp; &nbsp;  3
 /&nbsp;&nbsp;  \&nbsp; &nbsp; &nbsp;&nbsp;\
4&nbsp; &nbsp;  &nbsp;5&nbsp; &nbsp;  &nbsp;6
<strong>Output: </strong>[4, 2, 7, 5, 3, 6]</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= number of nodes &lt;= 3*10<sup>4<br></sup></span><span style="font-size: 18px;">1 &lt;= node-&gt;data &lt;= 10<sup>4</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Walmart</code>&nbsp;<code>BrowserStack</code>&nbsp;<code>Dell</code>&nbsp;<code>Grofers</code>&nbsp;<code>Netskope</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;