import express from 'express';

const app = express();
const port = 3000;

app.use(express.json());

let teaData = [];
let nextID = 1;

app.post('/teas', (req, res) => {
    const { name, price } = req.body;
    const newTea = { id: nextID++, name, price };
    teaData.push(newTea);
    res.status(201).send(newTea);
});

app.get('/teas', (_, res) => {
    res.send(teaData);
});

app.get('/teas/:id', (req, res) => {
    const tea = teaData.find(t => t.id === parseInt(req.params.id));
    if (!tea) {
        return res.status(404).send('Tea not found');
    }
    res.send(tea);
});

app.put('/teas/:id', (req, res) => {
    const tea = teaData.find(t => t.id === parseInt(req.params.id));
    if (!tea) {
        return res.status(404).send('Tea not found');
    }
    const { name, price } = req.body;
    tea.name = name;
    tea.price = price;
    res.send(tea);
});

app.delete('/teas/:id', (req, res) => {
    const teaIndex = teaData.findIndex(t => t.id === parseInt(req.params.id));
    if (teaIndex === -1) {
        return res.status(404).send('Tea not found');
    }
    const deletedTea = teaData.splice(teaIndex, 1);
    res.send(deletedTea);
});

app.listen(port, () => {
    console.log(`Server is running at port: ${port}...`);
});