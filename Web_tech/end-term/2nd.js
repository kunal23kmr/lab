function validateForm() {
    let isValid = true;
    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const contact = document.getElementById('cc').value;
    const namePattern = /^[A-Za-z\s]+$/;
    const emailPattern = /^[a-zA-Z][a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
    const contactPattern = /^[0-9]+$/;
    const nameError = document.getElementById('name-error');
    const emailError = document.getElementById('email-error');
    const contactError = document.getElementById('contact-error');
    if (!namePattern.test(name) || name === '') {
        nameError.innerHTML = "Invalid name";
        isValid = false;
    } else {
        nameError.innerHTML = "";
    }
    if (!emailPattern.test(email) || email === '') {
        emailError.innerHTML = "Invalid email";
        isValid = false;
    } else {
        emailError.innerHTML = "";
    }
    if (!contactPattern.test(contact) || contact === '' || contact.length !== 10) {
        contactError.innerHTML = "Invalid contact";
        isValid = false;
    } else {
        contactError.innerHTML = "";
    }
    return isValid;
}