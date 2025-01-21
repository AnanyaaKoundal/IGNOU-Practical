// Simulating storage for different nests
let nestStorage = {
    'Nest1': { scalpel: 'Nest2' },
    'Nest2': { scalpel: 'Nest3' },
    'Nest3': { scalpel: 'Nest4' },
    'Nest4': { scalpel: 'Nest1' }  // Points back to Nest1, the starting nest
};

// Simulated anyStorage function to access storage in different nests
async function anyStorage(nest) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if (nestStorage[nest]) {
                resolve(nestStorage[nest]);
            } else {
                reject(`No data for ${nest}`);
            }
        }, 500); // Simulate some delay in accessing the storage
    });
}

// Async function to locate the scalpel starting from a given nest
async function locateScalpel(startNest) {
    let currentNest = startNest;

    try {
        while (true) {
            // Get the next nest from the storage of the current nest
            const nextNest = await anyStorage(currentNest);
            console.log(`Scalpel is now at ${nextNest.scalpel}`);

            // Check if the scalpel is back at the starting nest
            if (nextNest.scalpel === startNest) {
                console.log(`Scalpel has returned to the starting nest: ${startNest}`);
                break;
            }

            // Move to the next nest in the breadcrumb trail
            currentNest = nextNest.scalpel;
        }
    } catch (error) {
        console.error("Error locating scalpel:", error);
    }
}

// Start the search from Nest1
locateScalpel('Nest1');
