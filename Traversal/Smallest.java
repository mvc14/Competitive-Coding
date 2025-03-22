{\rtf1\ansi\ansicpg1252\cocoartf2821
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red70\green137\blue204;\red30\green30\blue30;\red202\green202\blue202;
\red67\green192\blue160;\red140\green211\blue254;\red89\green138\blue67;\red212\green214\blue154;\red167\green197\blue152;
\red183\green111\blue179;}
{\*\expandedcolortbl;;\cssrgb\c33725\c61176\c83922;\cssrgb\c15686\c15686\c15686;\cssrgb\c83137\c83137\c83137;
\cssrgb\c30588\c78824\c69020;\cssrgb\c61176\c86275\c99608;\cssrgb\c41569\c60000\c33333;\cssrgb\c86275\c86275\c66667;\cssrgb\c70980\c80784\c65882;
\cssrgb\c77255\c52549\c75294;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs26 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 class\cf4 \strokec4  \cf5 \strokec5 Solution\cf4 \strokec4  \{\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf4 \cb3     \cf5 \strokec5 int\cf4 \strokec4  \cf6 \strokec6 val\cf4 \strokec4 ;\cb1 \
\cb3     \cf7 \strokec7 // approach it by dfs \cf4 \cb1 \strokec4 \
\cb3     \cf2 \strokec2 public\cf4 \strokec4  \cf5 \strokec5 int\cf4 \strokec4  \cf8 \strokec8 kthSmallest\cf4 \strokec4 (\cf5 \strokec5 TreeNode\cf4 \strokec4  \cf6 \strokec6 root\cf4 \strokec4 , \cf5 \strokec5 int\cf4 \strokec4  \cf6 \strokec6 k\cf4 \strokec4 ) \{\cb1 \
\cb3         \cf5 \strokec5 int\cf4 \strokec4  \cf6 \strokec6 check\cf4 \strokec4  = -\cf9 \strokec9 10000\cf4 \strokec4 ; \cf7 \strokec7 // compares the smallest \cf4 \cb1 \strokec4 \
\cb3         val = check; \cf7 \strokec7 // holds our current smallest \cf4 \cb1 \strokec4 \
\cb3         \cf8 \strokec8 dfs\cf4 \strokec4 (root, k, \cf9 \strokec9 0\cf4 \strokec4 , check);\cb1 \
\cb3         \cf10 \strokec10 return\cf4 \strokec4  val;\cb1 \
\cb3     \}\cb1 \
\
\
\cb3     \cf7 \strokec7 // currInd -> keeps track of the curr smallest \cf4 \cb1 \strokec4 \
\cb3     \cf7 \strokec7 // val -> keeps track of the root val\cf4 \cb1 \strokec4 \
\
\cb3     \cf2 \strokec2 public\cf4 \strokec4  \cf5 \strokec5 int\cf4 \strokec4  \cf8 \strokec8 dfs\cf4 \strokec4 (\cf5 \strokec5 TreeNode\cf4 \strokec4  \cf6 \strokec6 root\cf4 \strokec4 , \cf5 \strokec5 int\cf4 \strokec4  \cf6 \strokec6 k\cf4 \strokec4 , \cf5 \strokec5 int\cf4 \strokec4  \cf6 \strokec6 currInd\cf4 \strokec4 , \cf5 \strokec5 int\cf4 \strokec4  \cf6 \strokec6 check\cf4 \strokec4 ) \{ \cb1 \
\cb3         \cf10 \strokec10 if\cf4 \strokec4  (val != check) \{\cb1 \
\cb3             \cf10 \strokec10 return\cf4 \strokec4  currInd;\cb1 \
\cb3         \}\cb1 \
\
\cb3         \cf10 \strokec10 if\cf4 \strokec4  (root == \cf2 \strokec2 null\cf4 \strokec4 ) \{\cb1 \
\cb3             \cf10 \strokec10 return\cf4 \strokec4  currInd;\cb1 \
\cb3         \}\cb1 \
\
\cb3         currInd = \cf8 \strokec8 dfs\cf4 \strokec4 (\cf6 \strokec6 root\cf4 \strokec4 .\cf6 \strokec6 left\cf4 \strokec4 , k, currInd, check) + \cf9 \strokec9 1\cf4 \strokec4 ;\cb1 \
\
\cb3         \cf10 \strokec10 if\cf4 \strokec4  (currInd == k) \{\cb1 \
\cb3             val = \cf6 \strokec6 root\cf4 \strokec4 .\cf6 \strokec6 val\cf4 \strokec4 ;\cb1 \
\cb3             \cf10 \strokec10 return\cf4 \strokec4  currInd;\cb1 \
\cb3         \}\cb1 \
\
\cb3         \cf10 \strokec10 return\cf4 \strokec4  \cf8 \strokec8 dfs\cf4 \strokec4 (\cf6 \strokec6 root\cf4 \strokec4 .\cf6 \strokec6 right\cf4 \strokec4 , k, currInd, check);\cb1 \
\cb3     \}\cb1 \
\cb3 \}\cb1 \
}