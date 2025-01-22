// Base class for Book
class Book {
    constructor(title, author, copyrightDate, ISBN, numberOfPages, timesCheckedOut, discarded) {
        this.title = title;
        this.author = author;
        this.copyrightDate = copyrightDate;
        this.ISBN = ISBN;
        this.numberOfPages = numberOfPages;
        this.timesCheckedOut = timesCheckedOut;
        this.discarded = discarded;
    }
}

// Child class for Manual
class Manual extends Book {
    constructor(title, author, copyrightDate, ISBN, numberOfPages, timesCheckedOut, discarded) {
        super(title, author, copyrightDate, ISBN, numberOfPages, timesCheckedOut, discarded);
    }

    // Method to check if manual should be discarded
    checkForDisposal(currentYear) {
        const yearsOld = currentYear - this.copyrightDate;
        if (yearsOld > 5) {
            this.discarded = true;
            console.log(`${this.title} (Manual) is outdated and discarded.`);
        }
    }
}

// Child class for Novel
class Novel extends Book {
    constructor(title, author, copyrightDate, ISBN, numberOfPages, timesCheckedOut, discarded) {
        super(title, author, copyrightDate, ISBN, numberOfPages, timesCheckedOut, discarded);
    }

    // Method to check if novel should be discarded based on checkout times
    checkForDisposal() {
        if (this.timesCheckedOut > 100) {
            this.discarded = true;
            console.log(`${this.title} (Novel) has been checked out more than 100 times and discarded.`);
        }else{
            console.log(`${this.title} (Novel) has ${100 - this.timesCheckedOut} checkouts left before being discarded.`);
        }
    }

    // Method to update checkout count
    updateCheckoutCount() {
        this.timesCheckedOut += 1;
        console.log(`Checkout count for ${this.title}: ${this.timesCheckedOut}`);
    }
}

// Task 2: Create objects for Novel and Manual
let manualBook = new Manual("JavaScript Essentials", "John Doe", 2010, "123456789", 200, 0, false);
let novelBook = new Novel("Mystery in the Library", "Jane Doe", 2015, "987654321", 300, 50, false);

// Task 3: Check disposal based on current year and checkout times
manualBook.checkForDisposal(2022); // Check if Manual should be discarded (based on year)
novelBook.updateCheckoutCount();   // Update the checkout count for novel
novelBook.checkForDisposal();      // Check if Novel should be discarded (based on checkout times)
