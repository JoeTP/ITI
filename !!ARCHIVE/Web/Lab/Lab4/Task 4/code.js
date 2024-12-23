


 var answer = document.getElementById("Answer");

 function EnterNumber(val) { 
    answer.value += val 
    if (val.key == '0' || val.key == '1' 
        || val.key == '2' || val.key == '3' 
        || val.key == '4' || val.key == '5' 
        || val.key == '6' || val.key == '7' 
        || val.key == '8' || val.key == '9' 
        || val.key == '+' || val.key == '-' 
        || val.key == '*' || val.key == '/') 
        answer.value += val.key; 
} 

function EnterEqual() { 
    let y = math.eval(answer.value); 
    answer.value = y 
} 

function EnterClear() { 
    document.getElementById("Answer").value = "" 
} 