

var button = document.getElementById("sub");
button.addEventListener("click", validation);
console.log(button);
var email = document.getElementById("email");
console.log(email);

var span = document.createElement("span");
console.log(span);
const emailPattern = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;

function validateEmail(email) { return emailPattern.test(email); }


var inputs = document.querySelectorAll("input");
console.log(inputs);
inputs.forEach(input=> 
{
    input.addEventListener("focus", function () {
        input.style.border = "5px solid red";
    });
    
    input.addEventListener("blur", function () {
        input.style.border = "";
    });
}
);


function validation(e) {
    e.preventDefault();
    if (email.value === "") {
        span.textContent = "pls enter email";
        span.style.display = "inline";
        span.style.color = "red";
        email.insertAdjacentElement("afterend", span);
    }
    else if (!validateEmail(email.value)) {
        span.textContent = "invalid email format";
        span.style.display = "inline";
        span.style.color = "green";
    } else {
        span.textContent = "";
    }
}