// var b=document.body;
// console.log(typeof b);

// b.children[1]

// var mydiv=document.getElementsByTagName("div")[0];
// console.log(mydiv);
// var datadiv=document.getElementsByClassName("mydiv");
// console.log(datadiv);
// var id=document.getElementById("myid");
// console.log(id);

// change attributes 
//  var collection=document.getElementsByTagName("a");
// // collection[0].setAttribute("href","page2.html");
// collection[0].setAttribute("class","bgred");
// collection[0].classList.remove("myclass");
// collection[0].classList.remove("bgred");
// var span=document.getElementsByTagName("span")[0];
// console.log(span);
// span.style.backgroundColor="yellow";
// create new element 
// 1- create element variable 
// 2- add properties 
// 3- append the element to parent 

 //var newele=document.createElement("h2");
// console.log(newele);
//  newele.style.backgroundColor="green";
//  newele.textContent="hello new header 2";
//  document.body.insertBefore(newele,document.body.lastElementChild);
// // document.body.append(newele);

// var h1=document.getElementById("myid");
// document.body.append(h1.cloneNode(false));

// var num=prompt("pls enter number of employees");
// console.log(num);
// var names=[];
// var salaries=[];
// for(var i=0;i<Number(num);i++)
// {
//     var n=prompt("enter the emplyee name for no"+(i+1));
//     names.push(n);
   
//     var s=prompt("enter the employee salary for no"+(i+1));
//     salaries.push(s);
//     var tr=document.createElement("tr");
//     tr.style.color="red ";
//     tr.innerHTML="<td>"+names[i]+"</td> <td>"+salaries[i]+"</td>";
//     //console.log(tr);
//     document.getElementsByTagName("tbody")[0].append(tr);
// }

// var table=document.getElementsByTagName("table")[0].style.backgroundColor="yellow";
// document.getElementsByTagName("table")[0].style.display="table";
//console.log(names);
//console.log(salaries);

//  function test(e,div)
//  {
//  //console.log(e);

// // console.log(e.target.textContent);
//  //alert(e.target.textContent);
//  }
// // add event listener
// var div=document.getElementsByTagName("div")[0];
// div.addEventListener("click", function(e){
//     alert(e.target.textContent);

// }); // call back function i.e function body 

// var form =document.getElementsByTagName("form")[0];
// form.addEventListener("submit",validation);
// var input=document.getElementsByTagName("input")[0];//name
// var input1=document.getElementsByTagName("input")[1];//position
// var span=document.getElementsByTagName("span")[0];
// function validation(e)
// {
    
//     alert(input.value);
// if(input.value==="")
// {
//     e.preventDefault();
//  span.textContent="pls enter ur name " ;  
//  span.style.display="inline";
// }

// }

// window.addEventListener("contextmenu",function(e){
//    // e.preventDefault();
// })
// timer events 

// setTimeout(function(){

//     alert("hello")},2000)


var myinterval =setInterval(function(){
    console.log("hello interval");
}, 2000)

function clear(){
clearInterval(myinterval=null);
}