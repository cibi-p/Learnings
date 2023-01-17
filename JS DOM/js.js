const ul = document.querySelector('ul');
const li =  document.createElement('li');
ul.append(li);
li.innerText="hello";
console.log(ul.parentNode);
console.log(ul.parentElement);
console.log(ul.parentNode);
console.log(ul.childNodes);
console.log(ul.children);

li.classList.add('text');

let btn2=document.querySelector(".btn-2");
btn2.addEventListener("click", hello2);
const liattri=document.getElementsByClassName("text");
function hello()
{
    alert("hello");
}
function hello2()
{
    alert("inline buttorn alert");
}

var k=0;
let bt3=document.getElementById("bt-3");
console.log(bt3);
function cc(){
    if(k==0){
        k=1;
    for (var i=0; i<liattri.length; i++)
        liattri[i].style.color="green";
    bt3.innerText = "change text color to pink";
    }
    else{
        k=0;
    for (var i=0; i<liattri.length; i++)
        liattri[i].style.color="pink";
        bt3.innerText = "change text color to red";
    }
    console.log(bt3);
}