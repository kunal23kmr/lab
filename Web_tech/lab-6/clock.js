function updateClock() {
    document.getElementById('updateButton').style.display = 'inline';
    const clockElement = document.getElementById('clock');
    const currentTime = new Date();

    let hours = currentTime.getHours();
    let ampm = "AM";

    if (hours >= 12) {
        ampm = "PM";
        if (hours > 12) {
            hours -= 12;
        }
    }
    hours = hours.toString().padStart(2, '0');
    const minutes = currentTime.getMinutes().toString().padStart(2, '0');
    const seconds = currentTime.getSeconds().toString().padStart(2, '0');

    const timeString = `${hours}:${minutes}:${seconds} ${ampm}`;
    clockElement.textContent = timeString;
}
var state = true;
function reset() {
    if (state === true) {
        document.getElementById('clock').textContent = "";
        document.getElementById('reset').textContent = "Show";
        document.getElementById('updateButton').style.display = 'none';
    }else{
        document.getElementById('reset').textContent = "Hide";
        updateClock();
    }
    state = !state;
}
updateClock();
document.getElementById('updateButton').style.display = 'none';
reset();