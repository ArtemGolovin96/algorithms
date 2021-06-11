// Сортировка слиянием

const array = [4, 8, 7, 2, 11, 1, 3];

function mergeSortFunc(left: number[], rigth: number[]): number[] {
  let arr = [];
  while (left.length && rigth.length) {
    if (left[0] < rigth[0]) {
      arr.push(left.shift());
    } else {
      arr.push(rigth.shift());
    }
  }
  return [...arr, ...left, ...rigth]
}

function mergeSortArrayFunc(arr: number[]): number[] {
  const twice = arr.length / 2;

  if (arr.length < 2) {
    return arr;
  }

  const left = arr.splice(0, twice);
  let leftRes = mergeSortArrayFunc(left);
  let rigthRes = mergeSortArrayFunc(arr);
  return mergeSortFunc(leftRes, rigthRes);

}

console.log(mergeSortArrayFunc(array))