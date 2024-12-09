document.addEventListener("DOMContentLoaded", () => {
    const todoInput = document.getElementById("todo-input");
    const addTaskButton = document.getElementById("add-task-btn");
    const todoList = document.getElementById("todo-list");

    const tasks = [];

    addTaskButton.addEventListener("click", () => {
        const taskText = todoInput.value.trim();
        if(taskText === "") return;

        const newTask = {
            id: Date.now(),
            text: taskText,
            completed:false,
        };

        tasks.push(newTask);
        console.log(tasks);

        const li = document.createElement("li");
        li.textContent = taskText;

        todoList.appendChild(li);
        todoInput.value = "";
    })
})

