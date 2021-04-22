
<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<title>sorting</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta keywords="">
<style>

.CodeMirror {
  height: inherit;
}

.doc-embed {
  padding: 0;
  border: 1px solid #D2D3D6;
  border-radius: 3px;
  margin-bottom: 8px;

  color: #45474B;

  .doc-embed-wrapper {
    display: flex;
    align-items: stretch;
    flex-wrap: nowrap;
  }

  .collapse-trigger {
    flex: 0 0 auto;
    display: flex;
    flex-direction: column;
    padding-top: 4px;
    padding-left: 4px;
    cursor: pointer;
    overflow: hidden;

    .threadline {
      flex: 1 1 auto;
      width: 1px;
      background: #EDEDEE;
      transition: 0.2s
      display: block;
      margin: auto;
    }

    &:hover .threadline {
      width: 1px;
      background: #2C2D30
    }
  }

  svg {
    width: 40px;
    height: 40px;
    cursor: pointer;
    fill: currentColor;
  }

  &.collapsed {
    .collapse-trigger  {
      .threadline {
        display: none;
      }
      svg {
        transform: rotate(-90deg);
      }
    }
    .doc-embed-content {
      display: none;
    }
  }

  .embed-body {
    min-width: 0;
  }

  .doc-embed-header {
    display: flex;
    align-items: center;

    & > div {
      flex: 1;
      min-width: 0;
      padding: 8px 16px 8px 4px;
    }

    h1, a {
      white-space: nowrap;
      overflow: hidden;
      text-overflow: ellipsis;
    }

    h1 {
      font-size: 24px;
      margin: 0;
    }

    p {
      margin: 0;
    }

    a {
      display: block;
    }

    a > svg {
      margin-right: 5px;
      width: 20px;
      height: 20px;
      vertical-align: middle;
    }
  }

  .doc-embed-content {
    padding: 0 16px;
  }
}

-ms-text-size-adjust: 100%;
-webkit-text-size-adjust: 100%;
line-height: 1.6;
font-family: -apple-system, BlinkMacSystemFont, Segoe UI, Helvetica, Arial,
  sans-serif, Apple Color Emoji, Segoe UI Emoji, Segoe UI Symbol;
font-size: 16px;
line-height: 1.6;
word-wrap: break-word;

.dark, .solarizedDark {
  color: #FFF;
}

details {
  display: block;
}

summary {
  display: list-item;
}

a {
  background-color: transparent;
}

a:active,
a:hover {
  outline-width: 0;
}

strong {
  font-weight: inherit;
  font-weight: bolder;
}

h1 {
  font-size: 2em;
  margin: 0.67em 0;
}

img {
  border-style: none;
}

code,
kbd,
pre {
  font-family: monospace, monospace;
  font-size: 1em;
}

hr {
  box-sizing: content-box;
  height: 0;
  overflow: visible;
}

input {
  font: inherit;
  margin: 0;
}

input {
  overflow: visible;
}

[type='checkbox'] {
  box-sizing: border-box;
  padding: 0;
}

* {
  box-sizing: border-box;
}

input {
  font-family: inherit;
  font-size: inherit;
  line-height: inherit;
}

a {
  color: #0366d6;
  text-decoration: none;
}

a:hover {
  text-decoration: underline;
}

strong {
  font-weight: 600;
}

hr {
  background: transparent;
  border: 0;
  border-bottom: 1px solid #dfe2e5;
  height: 0;
  margin: 15px 0;
  overflow: hidden;
}

hr:before {
  content: '';
  display: table;
}

hr:after {
  clear: both;
  content: '';
  display: table;
}

table {
  border-collapse: collapse;
  border-spacing: 0;
}

td,
th {
  padding: 0;
}

details summary {
  cursor: pointer;
}

h1,
h2,
h3,
h4,
h5,
h6 {
  margin-bottom: 0;
  margin-top: 0;
}

h1 {
  font-size: 32px;
}

h1,
h2 {
  font-weight: 500;
}

h2 {
  font-size: 24px;
}

h3 {
  font-size: 20px;
}

h3,
h4 {
  font-weight: 500;
}

h4 {
  font-size: 16px;
}

h5 {
  font-size: 14px;
}

h5,
h6 {
  font-weight: 600;
}

h6 {
  font-size: 12px;
}

p {
  margin-bottom: 10px;
  margin-top: 0;
}

blockquote {
  margin: 0;
}

ol,
ul {
  margin-bottom: 0;
  margin-top: 0;
  padding-left: 0;
}

ol ol,
ul ol {
  list-style-type: lower-roman;
}

ol ol ol,
ol ul ol,
ul ol ol,
ul ul ol {
  list-style-type: lower-alpha;
}

dd {
  margin-left: 0;
}

code,
pre {
  font-family: SFMono-Regular, Consolas, Liberation Mono, Menlo, Courier,
    monospace;
  font-size: 12px;
}

pre.CodeMirror,
code.CodeMirror {
  height: auto;
}

pre {
  margin-bottom: 0;
  margin-top: 0;
}

input::-webkit-inner-spin-button,
input::-webkit-outer-spin-button {
  -webkit-appearance: none;
  appearance: none;
  margin: 0;
}

&:before {
  content: '';
  display: table;
}

&:after {
  clear: both;
  content: '';
  display: table;
}

> :first-child {
  margin-top: 0 !important;
}

> :last-child {
  margin-bottom: 0 !important;
}

a:not([href]) {
  color: inherit;
  text-decoration: none;
}

blockquote,
dl,
ol,
p,
pre,
table,
ul {
  margin-bottom: 16px;
  margin-top: 0;
}

hr {
  background-color: #e1e4e8;
  border: 0;
  height: 1px;
  margin: 16px 0;
  padding: 0;
}

blockquote {
  border-left: 0.25em solid #e1e4e8;
  color: #999999;
  padding: 0 1em;
}

blockquote > :first-child {
  margin-top: 0;
}

blockquote > :last-child {
  margin-bottom: 0;
}

kbd {
  background-color: #fafbfc;
  border: 1px solid #c6cbd1;
  border-bottom-color: #959da5;
  border-radius: 3px;
  box-shadow: inset 0 -1px 0 #959da5;
  color: #444d56;
  display: inline-block;
  font-size: 11px;
  line-height: 10px;
  padding: 3px 5px;
  vertical-align: middle;
}

h1,
h2,
h3,
h4,
h5,
h6 {
  line-height: 1.25;
  margin: 8px 0;
}

h1 {
  margin-top: 32px;
  font-weight: 600;
  font-size: 1.953em;
  margin-bottom: 10px;
}

h2 {
  font-weight: 600;
  font-size: 1.5em;
  margin-top: 16px;
  margin-bottom: 8px;
}

h3 {
  font-weight: 600;
  font-size: 1.25em;
}

h4 {
  font-weight: 400;
  font-size: 1em;
}

h5 {
  font-weight: 400;
  font-size: 0.875em;
}

h6 {
  font-weight: 400;
  color: #6a737d;
  font-size: 0.85em;
}

ol,
ul {
  padding-left: 2em;
}
ol ol,
ol ul,
ul ol,
ul ul {
  margin-bottom: 0;
  margin-top: 0;
}

li {
  word-wrap: break-all;
}

li > p {
  margin-top: 16px;

  &:first-child {
    margin-top: 0;
  }
  &:last-child {
    margin-bottom: 0;
  }
}

li + li {
  margin-top: 0.25em;
}

dl {
  padding: 0;
}

dl dt {
  font-size: 1em;
  font-style: italic;
  font-weight: 600;
  margin-top: 16px;
  padding: 0;
}

dl dd {
  margin-bottom: 16px;
  padding: 0 16px;
}

table {
  display: block;
  overflow: auto;
  width: 100%;
}

table th {
  font-weight: 600;
}

table td,
table th {
  border: 1px solid #dfe2e5;
  padding: 6px 13px;
}

table tr {
  border-top: 1px solid #c6cbd1;
}

img {
  display: block;
  max-width: 100%;
  height: auto;
  margin: 15px 0;
  box-sizing: content-box;
}

img[align='right'] {
  padding-left: 20px;
}

img[align='left'] {
  padding-right: 20px;
}

code {
  background-color: rgba(27, 31, 35, 0.05);
  border-radius: 3px;
  font-size: 85%;
  margin: 0;
  padding: 0.2em 0.4em;
}

p code,
li code
{
  padding: 2px;
  border-width: 1px;
  border-style: solid;
  border-radius: 5px;
}

pre {
  word-wrap: normal;
}

pre > code {
  background: transparent;
  border: 0;
  font-size: 100%;
  margin: 0;
  padding: 0;
  white-space: pre;
  word-break: normal;
}

.highlight {
  margin-bottom: 16px;
}

.highlight pre {
  margin-bottom: 0;
  word-break: normal;
}

.highlight pre,
pre {
  background-color: #f6f8fa;
  border-radius: 3px;
  font-size: 85%;
  line-height: 1.45;
  overflow: auto;
  padding: 16px;
}

pre code {
  background-color: transparent;
  border: 0;
  display: inline;
  line-height: inherit;
  margin: 0;
  max-width: auto;
  overflow: visible;
  padding: 0;
  word-wrap: normal;
}

kbd {
  background-color: #fafbfc;
  border: 1px solid #d1d5da;
  border-bottom-color: #c6cbd1;
  border-radius: 3px;
  box-shadow: inset 0 -1px 0 #c6cbd1;
  color: #444d56;
  display: inline-block;
  font: 11px SFMono-Regular, Consolas, Liberation Mono, Menlo, Courier,
    monospace;
  line-height: 10px;
  padding: 3px 5px;
  vertical-align: middle;
}

:checked + .radio-label {
  border-color: #0366d6;
  position: relative;
  z-index: 1;
}

.task-list-item {
  position: relative;
  list-style-type: none;
  height: fit-content;
  min-height: 25px;
}

.task-list-item + .task-list-item {
  margin-top: 3px;
}

.task-list-item input {
  margin: 0 0.2em 0.25em -1.6em;
  vertical-align: middle;
}

.task-list-item input[type=checkbox] {
  position: absolute;
  top: 6px;
}

hr {
  border-bottom-color: #eee;
}

.dark p code,
.dark li code
{
  background-color: rgba(255,255,255,0.12);
  border-color: rgba(255,255,255,0.3);
  color: #5580DC;
}

.auto p code,
.auto li code
{
  background-color: #F9F9F9;
  border-color: rgba(0,0,0,0.26);
  color: #5580DC;
}

.light p code,
.light li code
{
  background-color: #F9F9F9;
  border-color: rgba(0,0,0,0.26);
  color: #5580DC;
}

.sepia p code,
.sepia li code
{
  background-color: #efe8d6;
  border-color: rgba(0,0,0,0.26);
  color: #F77942;
}

.solarizedDark p code,
.solarizedDark li code
{
  background-color: rgba(255,255,255,0.12);
  border-color: rgba(255,255,255,0.3);
  color: #36abe3;
}

.column {
  float: left;
  width: 33.33%;
  padding: 5px;
}

/* Clear floats after image containers */
.row::after {
  content: "";
  clear: both;
  display: table;
}  
  
</style>
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/katex@0.11.1/dist/katex.min.css">
</head>
<body>
<h2>Sorting Techniques</h2>
<h4>CSL 102; Data Structures; IIIT Nagpur; Created by: Dr. Aniket Pingley</h4>
<p><strong>Selection Sort</strong></p>
<p>This way of sorting is simplest to imagine. We tend to utilize the principle of selection sort in our day-to-day lives. Assume that we wish to sort a series of values in ascending order. Intuitvely, we will first traverse through an array an select the smallest element and keep it aside. From the remaining elements in the array we will again repeat the steps to find and keep the smallest element aside. </p>
<br>
<p><strong>Example of Selection Sort:</strong></p>
<p>Conside the following array consisting of 6 elements: [23, 4, 56, 1, 78, 2]</p>
<ul>
<li>Step 1: Set starting index = 0 and find the index at which the smallest element is located. In this case 1 is located at index 3.</li>
<li>Step 2: Swap elements at starting index and index 3. The modified array is [1, 4, 56, 23, 78, 2]</li>
<li>Step 3: Increment the starting index by 1. Now the subarray to consider indexes from 1 through 5. </li>
<li>Step 4: The element 2 at index 5 is the smallest. Swap the elements at index 1 and index 5. The modified array now is [1, 2, 56, 23, 78, 4]</li>
<li>.....</li>
<li>.....</li>
<li>Repeat the steps until the starting index equals to 5 (last index)</li>
</ul>
<p>The following flowchart demonstrates the flow of selection sort algorithm/method. </p>
<p><img src="images/e5e96e67-d096-48a2-bf86-92674538d1f9.svg" width="30%" height="30%"></p>
<p>Link to animation for selection sort - <a href="https://yongdanielliang.github.io/animation/web/SelectionSortNew.html">https://yongdanielliang.github.io/animation/web/SelectionSortNew.html</a></p>

<pre class="cm-s-default CodeMirror"><code>
  void selectionSort(int arr[], int n){
    int minIdx = 0;
    for (int i = 0; i < n-1; i++){
        minIdx = i;
        for (int j = i+1; j < n; j++){
          if (arr[j] < arr[minIdx]){
            minIdx = j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
      }
  }
  </code></pre>
  
<hr>
<p><strong>Bubble Sort</strong></p>
Bubble sort is a simple sorting algorithm that repeatedly iterates through an array, compares adjacent elements and swaps them if they are in the wrong order (assume ascending). The iteration through the array is repeated until the array is sorted.  

<p><strong>Example of Bubble Sort and Flowchart:</strong></p>
<div class="row">
  <div class="column">
    <img src="images/7f759078-231f-4122-8243-0f2677c64b46.png">
  </div>
  <div class="column">
    <img src="images/fe53c8b9-bd45-4b5d-88c1-a8a8cfe942ce.svg">
  </div>
</div>

<p>Link to animation for bubble sort - <a href="https://yongdanielliang.github.io/animation/web/BubbleSortNew.html">https://yongdanielliang.github.io/animation/web/BubbleSortNew.html</a></p>

<pre class="cm-s-default CodeMirror"><code>
  void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++){	
	    for (int j = 0; j < n-i-1; j++){
		    if (arr[j] > arr[j+1]){
			    swap(&arr[j], &arr[j+1]);
            }
        }
    }
  }
</code></pre>
<hr>
<p><strong>Insertion Sort</strong></p>
Insertion sort works similar to the way people sort playing cards in their hands. To sort an array of size n in ascending order:
<li>Step 1: Iterate from arr[1] to arr[n] over the array.</li>
<li>Step 2: Compare the current element (key) to its predecessor (element at the previous index).</li>
<li>Step 3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element. </li>
<li>Step 4: Repeat until the iteration reaches the last index of the array.</li>

<br>
<p><strong>Example of Insertion Sort and Flowchart:</strong></p>
<div class="row">
  <div class="column">
    <img src="images/608ad123-b753-4fc2-9929-285cb0660ada.png">
    Image source: GeeksForGeeks
  </div>
  <div class="column">
    <img src="images/937c6459-c1cb-4d70-9ccc-b1b451331acd.svg">
  </div>
</div>

<p>Link to animation for insertion sort - <a href="https://yongdanielliang.github.io/animation/web/InsertionSortNew.html">https://yongdanielliang.github.io/animation/web/InsertionSortNew.html</a></p>

<pre class="cm-s-default CodeMirror"><code>
  void insertionSort(int arr[], int n){
	int key = 0;
    	int j = 0;
	for (int i = 1; i < n; i++) {
	   key = arr[i];
	   j = i - 1;

	   while (j >= 0 && arr[j] > key) {
		arr[j + 1] = arr[j];
		j = j - 1;
	   }
	   arr[j + 1] = key;
	}
   }
</code></pre>
<hr>
<p><strong>Merge Sort</strong></p>
<p>The aforesaid sorting techniques require nearly <em>n<sup>2</sup></em> number of steps for input size <em>n</em>. Merge Sort technique is comparitvely more efficient. Similar to Binary Search it is a Divide and Conquer algorithm. To this end, it divides the input array into two halves. Each half is sorted by recursively dividing them individually into two halves. Once the entire array is divided into subarrays of size 1, they are merged into two sorted (ascensding) halves. Described below is the algorithm for merge sort technique.</p>
<p>merge_sort(arr[], left_index,  right_index)<br><br>
If right_index > left_index  
<ul>
  <li>Step 1: Find the middle point to divide the array into two halves:</li>  
  &nbsp;&nbsp;&nbsp;&nbsp; middle_index = (left_index + right_index)/2
  <li>Step 2: Call merge_sort for first half:</li>   
  &nbsp;&nbsp;&nbsp;&nbsp; Call merge_sort(arr, left_index, middle_index)
  <li>Step 3: Call merge_sort for second half:</li>
  &nbsp;&nbsp;&nbsp;&nbsp; Call merge_sort(arr, middle_index + 1, right_index)
  <li>Step 4: Merge the two halves sorted in step 2 and 3:</li>
  &nbsp;&nbsp;&nbsp;&nbsp; Call merge(arr, left_index, middle_index, right_index)
</ul>
<img src="images/38bdef27-dff4-40c1-a9af-76fe1e7477c8.png">
Image source: https://levelup.gitconnected.com/
</p>
<p>
The number of steps required for merge sort for input size <em>n</em> is:
<ul>
  <li>Recursive splitting of array: <em>log<sub>2</sub>(n)</em></li>
  <li>Merging of sorted arrays: <em>log<sub>2</sub>(n)</em></li>
  <li>Comparison of values at every step: <em>n</em></li>
  <li>Total steps = <em>log<sub>2</sub>(n)</em> + <em>log<sub>2</sub>(n)</em> * <em>n</em> = <em>nlog<sub>2</sub>(n)</em></li>
</ul>
</p>

<pre class="cm-s-default CodeMirror"><code>
  void merge(int arr[], int left_index, int middle_index, int right_index)
  {
    int sz_left_arr = middle_index - left_index + 1;
    int sz_right_arr = right_index - middle_index;
  
    /* create temporary arrays */
    int left_arr[sz_left_arr], right_arr[sz_right_arr];
  
    /* Copy data to left_arr[] and right_arr[] */
    for (int i = 0; i < sz_left_arr; i++)
      left_arr[i] = arr[left_index + i];
  
    for (int j = 0; j < sz_right_arr; j++)
      right_arr[j] = arr[middle_index + 1 + j];
  
    int i, j, k;
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; /* starting index of left_arr */
    j = 0; /* starting index of right_arr */
    k = left_index; /* starting index of merged subarray */
    while (i < sz_left_arr && j < sz_right_arr) {
      if (left_arr[i] <= right_arr[j]) {
        arr[k] = left_arr[i];
        i++;
      }
      else {
        arr[k] = right_arr[j];
        j++;
      }
      k++;
    }
  
    /* Copy the remaining elements of left_arr[], if there
    are any */
    while (i < sz_left_arr) {
      arr[k] = left_arr[i];
      i++;
      k++;
    }
  
    /* Copy the remaining elements of right_arr[], if there
    are any */
    while (j < sz_right_arr) {
      arr[k] = right_arr[j];
      j++;
      k++;
    }
  }
  
  void merge_sort_func(int arr[], int left_index, int right_index)
  {
    if (left_index < right_index) {
      int middle_index = (left_index + right_index) / 2;
  
      /*recursively sort first and second halves*/
      merge_sort_func(arr, left_index, middle_index);
      merge_sort_func(arr, middle_index + 1, right_index);
  
      merge(arr, left_index, middle_index, right_index);
    }
  } 
</code></pre>


<br>
<a href="../csl102.html">HOME</a>&nbsp;&nbsp;&nbsp;<a href="searching.html">PREV</a>&nbsp;&nbsp;&nbsp;<a href="sorting.html">NEXT</a>  
<br><br>
<div id="colorstrip"/>
<br>
<br>
<br>   
</body>
</html>
