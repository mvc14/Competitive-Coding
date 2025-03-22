{\rtf1\ansi\ansicpg1252\cocoartf2821
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red70\green137\blue204;\red30\green30\blue30;\red202\green202\blue202;
\red67\green192\blue160;\red89\green138\blue67;\red212\green214\blue154;\red140\green211\blue254;\red183\green111\blue179;
\red167\green197\blue152;}
{\*\expandedcolortbl;;\cssrgb\c33725\c61176\c83922;\cssrgb\c15686\c15686\c15686;\cssrgb\c83137\c83137\c83137;
\cssrgb\c30588\c78824\c69020;\cssrgb\c41569\c60000\c33333;\cssrgb\c86275\c86275\c66667;\cssrgb\c61176\c86275\c99608;\cssrgb\c77255\c52549\c75294;
\cssrgb\c70980\c80784\c65882;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs26 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 class\cf4 \strokec4  \cf5 \strokec5 LongestSubstring\cf4 \strokec4  \{\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf4 \cb3     \cf6 \strokec6 // using set sliding window (O(n^2))\cf4 \cb1 \strokec4 \
\cb3     \cf2 \strokec2 public\cf4 \strokec4  \cf5 \strokec5 int\cf4 \strokec4  \cf7 \strokec7 lengthOfLongestSubstring\cf4 \strokec4 (\cf5 \strokec5 String\cf4 \strokec4  \cf8 \strokec8 s\cf4 \strokec4 ) \{\cb1 \
\cb3         \cf5 \strokec5 HashSet\cf4 \strokec4 <\cf5 \strokec5 Character\cf4 \strokec4 > \cf8 \strokec8 set\cf4 \strokec4  = \cf9 \strokec9 new\cf4 \strokec4  \cf5 \strokec5 HashSet\cf4 \strokec4 <>();\cb1 \
\cb3         \cf5 \strokec5 int\cf4 \strokec4  \cf8 \strokec8 left\cf4 \strokec4  = \cf10 \strokec10 0\cf4 \strokec4 , max = \cf10 \strokec10 0\cf4 \strokec4 ;\cb1 \
\
\cb3         \cf9 \strokec9 for\cf4 \strokec4  (\cf5 \strokec5 int\cf4 \strokec4  \cf8 \strokec8 right\cf4 \strokec4  = \cf10 \strokec10 0\cf4 \strokec4 ; right < \cf8 \strokec8 s\cf4 \strokec4 .\cf7 \strokec7 length\cf4 \strokec4 (); right++) \{\cb1 \
\
\cb3             \cf9 \strokec9 while\cf4 \strokec4  (\cf8 \strokec8 set\cf4 \strokec4 .\cf7 \strokec7 contains\cf4 \strokec4 (\cf8 \strokec8 s\cf4 \strokec4 .\cf7 \strokec7 charAt\cf4 \strokec4 (right))) \{\cb1 \
\cb3                 \cf8 \strokec8 set\cf4 \strokec4 .\cf7 \strokec7 remove\cf4 \strokec4 (\cf8 \strokec8 s\cf4 \strokec4 .\cf7 \strokec7 charAt\cf4 \strokec4 (left));\cb1 \
\cb3                 left++;\cb1 \
\cb3             \}\cb1 \
\
\cb3             \cf8 \strokec8 set\cf4 \strokec4 .\cf7 \strokec7 add\cf4 \strokec4 (\cf8 \strokec8 s\cf4 \strokec4 .\cf7 \strokec7 charAt\cf4 \strokec4 (right));\cb1 \
\cb3             max = \cf8 \strokec8 Math\cf4 \strokec4 .\cf7 \strokec7 max\cf4 \strokec4 (max, right - left + \cf10 \strokec10 1\cf4 \strokec4 ); \cb1 \
\cb3         \}\cb1 \
\cb3         \cf9 \strokec9 return\cf4 \strokec4  max;\cb1 \
\
\cb3         \cf6 \strokec6 // optimized solution\cf4 \cb1 \strokec4 \
\cb3         \cf5 \strokec5 int\cf4 \strokec4  \cf8 \strokec8 max\cf4 \strokec4  = \cf10 \strokec10 0\cf4 \strokec4 , n = \cf8 \strokec8 s\cf4 \strokec4 .\cf7 \strokec7 length\cf4 \strokec4 ();\cb1 \
\cb3         \cf5 \strokec5 Map\cf4 \strokec4 <\cf5 \strokec5 Character\cf4 \strokec4 , \cf5 \strokec5 Integer\cf4 \strokec4 > \cf8 \strokec8 map\cf4 \strokec4  = \cf9 \strokec9 new\cf4 \strokec4  \cf5 \strokec5 HashMap\cf4 \strokec4 <>();\cb1 \
\cb3         \cf9 \strokec9 for\cf4 \strokec4  (\cf5 \strokec5 int\cf4 \strokec4  \cf8 \strokec8 j\cf4 \strokec4  = \cf10 \strokec10 0\cf4 \strokec4 , i = \cf10 \strokec10 0\cf4 \strokec4 ; j < n; j++) \{\cb1 \
\
\cb3             \cf9 \strokec9 if\cf4 \strokec4  (\cf8 \strokec8 map\cf4 \strokec4 .\cf7 \strokec7 containsKey\cf4 \strokec4 (\cf8 \strokec8 s\cf4 \strokec4 .\cf7 \strokec7 charAt\cf4 \strokec4 (j))) \{\cb1 \
\cb3                 i = \cf8 \strokec8 Math\cf4 \strokec4 .\cf7 \strokec7 max\cf4 \strokec4 (\cf8 \strokec8 map\cf4 \strokec4 .\cf7 \strokec7 get\cf4 \strokec4 (\cf8 \strokec8 s\cf4 \strokec4 .\cf7 \strokec7 charAt\cf4 \strokec4 (j)), i);\cb1 \
\cb3             \}\cb1 \
\cb3             max = \cf8 \strokec8 Math\cf4 \strokec4 .\cf7 \strokec7 max\cf4 \strokec4 (max, j - i +\cf10 \strokec10 1\cf4 \strokec4 );\cb1 \
\cb3             \cf8 \strokec8 map\cf4 \strokec4 .\cf7 \strokec7 put\cf4 \strokec4 (\cf8 \strokec8 s\cf4 \strokec4 .\cf7 \strokec7 charAt\cf4 \strokec4 (j), j + \cf10 \strokec10 1\cf4 \strokec4 );\cb1 \
\cb3         \}\cb1 \
\
\cb3         \cf9 \strokec9 return\cf4 \strokec4  max;\cb1 \
\cb3     \}\cb1 \
\cb3 \}\cb1 \
}