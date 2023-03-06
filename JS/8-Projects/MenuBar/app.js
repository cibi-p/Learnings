const navToggle= document.querySelector(".nav-toggles");
const links= document.querySelector(".links");

navToggle.addEventListener('click', function(){
    if(links.classList.contains('show-links')){
        links.classList.remove('show-links');
        navToggle.style.transform="rotate(0deg)";
    }
    else{
        links.classList.add("show-links");
        navToggle.style.transform="rotate(45deg)";
    }
})