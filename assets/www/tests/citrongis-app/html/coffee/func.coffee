counter = 0

this.coffeeFunc = () ->
    counter++
    nd = document.getElementById "coffee_span"
    nd.innerHTML = "You clicked: " + counter + " times"
