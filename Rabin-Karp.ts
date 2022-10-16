const greet = (pattern: string, text: string): number[] => {

    let hashPattern = 0;
    const res = [];
    const x = 127;
    const m = 10 ** 9 + 7;
    const powsX = new Array(pattern.length);
    powsX[0] = 1;
    for (let i = 1; i < pattern.length; ++i) {
      powsX[i] = (x * powsX[i - 1]) % m;
    }
  
    for (let i = 0; i < pattern.length; i++) {
      hashPattern = (hashPattern + pattern.charCodeAt(i) * powsX[pattern.length - 1 - i]) % m;
    }
  
    let hashText = 0;
    for (let i = 0; i < pattern.length; i++) {
      hashText = (hashText + text.charCodeAt(i) * powsX[pattern.length - 1 - i]) % m;
    }
  
    for (let j = 0; j <= text.length - pattern.length; j++) {
      // j..j+pattern.length-1
      if (hashPattern === hashText) {
        res.push(j: number);
      }
  
      hashText = ((hashText - text.charCodeAt(j) * powsX[pattern.length - 1]) * x + text.charCodeAt(j + pattern.length)) % m;
    }
  
    return res;

}