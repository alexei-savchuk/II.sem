
//МЕНЮ
const menuItems = document.querySelectorAll('.menu-main li a');

menuItems.forEach(item => {
  item.addEventListener('mouseover', () => {
    item.classList.add('active');
  });

  item.addEventListener('mouseout', () => {
    item.classList.remove('active');
  });
});

//БЛОК С ИЗОБРАЖЕНИЕМ И ТЕКСТОМ


window.onload = function() {

	setTimeout(function() {
	  document.querySelector('.image-text').style.opacity = '1';
	},1000);
  };




  
  
  //БЛОК СЛАЙДЕР

  window.onload = function(){
  
	const prevBtn = document.getElementById('prev');
	const nextBtn = document.getElementById('next');
   
	prevBtn.addEventListener("click",function(){
	  prevSlide();
   });
	nextBtn.addEventListener("click",function(){
	  nextSlide();
   });
	
  }
  let slideNumber = 0;
  const prevSlide = () =>{
	const slides = document.getElementsByClassName('slides');
  const slider = document.getElementById("slider");
	const currentSlide = slider.getElementsByClassName('current');
	currentSlide[0].classList.remove("current");
	if(slideNumber == 0){
	  slideNumber = slides.length-1;
	}
	else{
		slideNumber = slideNumber-1;
	}
	slides[slideNumber].classList.add("current");
  }
  const nextSlide = () =>{
	const slides = document.getElementsByClassName('slides');
  const slider = document.getElementById("slider");
	const currentSlide = slider.getElementsByClassName('current');
	currentSlide[0].classList.remove("current");
	if(slideNumber == (slides.length-1)){
	  slideNumber = 0;
	}
	else{
		slideNumber = slideNumber+1;
	}
	slides[slideNumber].classList.add("current");
  }