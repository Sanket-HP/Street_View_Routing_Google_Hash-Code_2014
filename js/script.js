document.addEventListener("DOMContentLoaded", () => {
    const form = document.getElementById("input-form");
    const junctionsCoordinatesDiv = document.getElementById("junctions-coordinates");
    const streetsDetailsDiv = document.getElementById("streets-details");

    form.junctions.addEventListener("change", updateJunctionsInputs);
    form.streets.addEventListener("change", updateStreetsInputs);

    form.addEventListener("submit", (e) => {
        e.preventDefault();
        const formData = new FormData(form);
        const result = processInput(formData);
        displayResult(result);
    });

    function updateJunctionsInputs() {
        const junctionsCount = form.junctions.value;
        junctionsCoordinatesDiv.innerHTML = '<h3>Junction Coordinates</h3><p>Enter latitude and longitude for each junction.</p>';
        for (let i = 0; i < junctionsCount; i++) {
            const latInput = document.createElement("input");
            latInput.type = "number";
            latInput.name = `lat${i}`;
            latInput.placeholder = `Latitude for Junction ${i}`;
            latInput.required = true;

            const lonInput = document.createElement("input");
            lonInput.type = "number";
            lonInput.name = `lon${i}`;
            lonInput.placeholder = `Longitude for Junction ${i}`;
            lonInput.required = true;

            junctionsCoordinatesDiv.appendChild(latInput);
            junctionsCoordinatesDiv.appendChild(lonInput);
        }
    }

    function updateStreetsInputs() {
        const streetsCount = form.streets.value;
        streetsDetailsDiv.innerHTML = '<h3>Streets Details</h3><p>Enter details for each street.</p>';
        for (let i = 0; i < streetsCount; i++) {
            const streetInput = document.createElement("input");
            streetInput.type = "text";
            streetInput.name = `street${i}`;
            streetInput.placeholder = `Details for Street ${i}`;
            streetInput.required = true;

            streetsDetailsDiv.appendChild(streetInput);
        }
    }

    function processInput(formData) {
        const junctions = formData.get("junctions");
        const streets = formData.get("streets");
        const totalTime = formData.get("total-time");
        const cars = formData.get("cars");
        const startJunction = formData.get("start-junction");

        const junctionCoords = [];
        for (let i = 0; i < junctions; i++) {
            const lat = formData.get(`lat${i}`);
            const lon = formData.get(`lon${i}`);
            junctionCoords.push({ lat, lon });
        }

        const streetsData = [];
        for (let i = 0; i < streets; i++) {
            const details = formData.get(`street${i}`);
            const [A, B, D, C, L] = details.split(" ").map(Number);
            streetsData.push({ A, B, D, C, L });
        }

        // Simulate processing the data and generating a result
        const result = `Processed data for ${cars} cars starting from junction ${startJunction}.\nJunctions: ${JSON.stringify(junctionCoords)}\nStreets: ${JSON.stringify(streetsData)}`;
        return result;
    }

    function displayResult(result) {
        const resultDiv = document.getElementById("result");
        resultDiv.textContent = result;
    }
});
