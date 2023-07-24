const boxes = document.querySelectorAll('.box');

window.addEventListener('scroll',checkboxes);

checkboxes();
function checkboxes(){
    const triggerbutton =window.innerHeight/5*3;
    boxes.forEach(box =>{
        const boxTop=box.getBoundingClientRect().top;
        console.log(boxTop);
        if(boxTop < triggerbutton){
            box.classList.add('show');
        }
        else{
            box.classList.remove('show');
        }
    })
}