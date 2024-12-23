console.log("=============REVERSE MANUALLY=================");
/*
var s = "123456789";
var r = "";
console.log(s);
for (var i = s.length -1; i >= 0; i--) {
    r += s[i];
}
console.log(r);
*/
/////////////////////////////////////////////////
console.log("==============CHECK EXISTANCE================");
/////////////////////////////////////////////////
/*
var A = [3,0,2,1,5,7];
var x = prompt();
var num = Number(x);
var found = false;

for(let i = 0; i<A.length; i++){
    if(A[i] == num){
        console.log("value: " + num + " found at index: " + i);
        found = true;
        break;
    }
}
if(!found){console.log(-1 + " NOT FOUND");}
*/
/////////////////////////////////////////////////
console.log("==============REMOVE AT INDEX================");
/////////////////////////////////////////////////
/*
var A = [3,0,2,1,5,7];
var nA = [];
var x = prompt();
var num = Number(x);
for(let i = 0; i<A.length; i++){
    if(A[i] != num){
        nA.push(A[i]);
   }
}
console.log(nA);
*/
/////////////////////////////////////////////////
console.log("==============CHECK PALINDROME================");
/////////////////////////////////////////////////
/*
var s1 = "madam";
var s2 = "kayak";
var s3 = "hello";
var s4 = "rotor";
function check(s) {
    var r = String(s.split('').reverse().join(''));
    if(s == r){
        console.log("YES");
        return true;
    }
    console.log("NO");
    return false;
}
check(s4);
*/
/////////////////////////////////////////////////
console.log("==============STUDENTS DEGREES================");
/////////////////////////////////////////////////
/*
var ar = [60, 100,10,15,85,70,45,30];
var av;
var sum = 0;
var pass = 0;
for (let i = 0; i < ar.length; i++) {
    sum += ar[i];
    av  = sum / ar.length;
    if(ar[i] >= 60){
        pass++;
    }
}
console.log(pass);
console.log(av);
console.log(sum);
*/
/////////////////////////////////////////////////
console.log("==============SUMMATION================");
/////////////////////////////////////////////////

var n ;
var sum = 0;

while (sum <= 100 && n !=0 ) {
    n = prompt("Total sum = " + sum);
    if (n != 0 && isNaN(n) == false && isFinite(n)) {
        sum += Number(n);
    } 

}
if (sum > 100) {
    alert("Sum Exceeded 100");
}
 else if (n == 0) {
    alert("U quited 😔");
}
    