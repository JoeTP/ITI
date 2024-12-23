

document.getElementById("mainImage").addEventListener("click", function() { // Hide the main image 
    this.style.display = "none"; // Show the left and right images 
    document.getElementById("leftImage").style.display = "inline"; 
    document.getElementById("rightImage").style.display = "inline";
});

