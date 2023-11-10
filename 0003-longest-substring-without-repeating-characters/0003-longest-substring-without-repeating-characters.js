/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    var start = 0;
    var maximum = 0;
    var char_Dict = {};
   
   for(let i = 0; i < s.length; i++){
       let char = s[i];
       if((char in char_Dict) && (char_Dict[char] >= start)){
           start = char_Dict[char] + 1;
       }
       char_Dict[char] = i;
       maximum = maximum > i - start + 1 ? maximum : i - start + 1;
   }
  return maximum;
};