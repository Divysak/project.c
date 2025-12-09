function showSection(id) {
    document.querySelectorAll('.section').forEach(sec => sec.style.display = "none");
    document.getElementById(id).style.display = "block";

    if (id === "code") {
        fetch("class.txt")
        .then(res => res.text())
        .then(data => {
            document.getElementById("codeBlock").textContent = data;
        });
    }
}
