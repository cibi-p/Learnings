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
