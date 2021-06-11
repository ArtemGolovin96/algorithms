// Сортировка слиянием
var __spreadArray = (this && this.__spreadArray) || function (to, from) {
    for (var i = 0, il = from.length, j = to.length; i < il; i++, j++)
        to[j] = from[i];
    return to;
};
var array = [4, 8, 7, 2, 11, 1, 3];
function mergeSortFunc(left, rigth) {
    var arr = [];
    while (left.length && rigth.length) {
        if (left[0] < rigth[0]) {
            arr.push(left.shift());
        }
        else {
            arr.push(rigth.shift());
        }
    }
    return __spreadArray(__spreadArray(__spreadArray([], arr), left), rigth);
}
function mergeSortArrayFunc(arr) {
    var twice = arr.length / 2;
    if (arr.length < 2) {
        return arr;
    }
    var left = arr.splice(0, twice);
    var leftRes = mergeSortArrayFunc(left);
    var rigthRes = mergeSortArrayFunc(arr);
    return mergeSortFunc(leftRes, rigthRes);
}
console.log(mergeSortArrayFunc(array));
