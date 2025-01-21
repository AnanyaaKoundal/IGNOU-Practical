// Product Class
class Product {
    constructor(ID, name, description, price) {
        this.ID = ID;
        this.name = name;
        this.description = description;
        this.price = price;
    }

    // Function to display product details
    displayProductDetails() {
        console.log(`Product ID: ${this.ID}`);
        console.log(`Name: ${this.name}`);
        console.log(`Description: ${this.description}`);
        console.log(`Original Price: $${this.price}`);
    }

    // Function to calculate discounted price
    calculateDisc(percentage) {
        const discountAmount = (this.price * percentage) / 100;
        const discountedPrice = this.price - discountAmount;
        console.log(`Discounted Price: $${discountedPrice}`);
    }
}

// Creating an instance of the Product class
let product = new Product(101, "Smartphone", "Latest model with great features", 799);

// Calling displayProductDetails and calculateDisc
product.displayProductDetails();
product.calculateDisc(20); // Assuming the user wants a 20% discount
