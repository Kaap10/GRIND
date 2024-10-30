function showResponse(response) {
    let message = "";
    if (response === 'love') {
        message = "I love you too!";
        document.getElementById('commentSection').style.display = 'none';
    } else if (response === 'nhi') {
        message = "Why not me? Kyu kon mil gya";
        document.getElementById('commentSection').style.display = 'block';
    }
    document.getElementById('response').innerText = message;
}

function submitComment() {
    const comment = document.getElementById('commentBox').value;
    if (comment.trim() !== '') {
        document.getElementById('commentResponse').innerHTML = `But I love you, aise dil mat todo <3 <br> Your comment: ${comment}`;
    } else {
        document.getElementById('commentResponse').innerText = 'Please type your reason.';
    }
}
