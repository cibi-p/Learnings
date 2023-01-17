const ul = document.querySelector('ul');
const li =  document.createElement('li');
ul.append(li);
li.innerText="hello";
console.log(ul);
li.setAttribute("class","text")