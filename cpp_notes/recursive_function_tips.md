# 1. 只要是递归，都考虑下把重复的缓存。such as fibonachi

f1 20分，f2 80分, f3 100分

'''
/**
* 从0算起第n个
*/
var first = 1;
var second = 1;

function fib1(n) {
if (n == 0) {
return first;
} else if (n == 1) {
return second;
}
return fib1(n - 1) + fib1(n - 2);
}

'''

var cache = new Array();
cache.push(first);
cache.push(second);
function fib2(n) {
if (cache[n]) {
return cache[n];
}
cache[n] = fib2(n - 1) + fib2(n - 2);
return cache[n];
}

'''
function funcFactory (cache, formula) {
console.assert(cache instanceof Array);
console.assert(formula instanceof Function);
// clear
cache.length = 0;
var recur = function (n) {
if (cache[n]) {
return cache[n];
}
cache[n] = formula(recur, n);
return cache[n];
}
return recur;
}
''''

## 尾递归/闭包
https://blog.csdn.net/superwangxinrui/article/details/79626870
