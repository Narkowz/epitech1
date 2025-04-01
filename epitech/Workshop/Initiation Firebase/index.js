import { initializeApp } from "firebase/app";
import { getFirestore } from "firebase/firestore";
import { doc, getDoc, setDoc } from "firebase/firestore";
// import serviceAccount from "workshop-421109-1950ec0191f2.json";
import express from "express";

const app = express()
const port = 3000

const firebaseConfig = {
    apiKey: "AIzaSyCJrXSk6l_AFvbr_OZfb0jrUEo6FpiMxeg",
    authDomain: "workshop-dd355.firebaseapp.com",
    projectId: "workshop-dd355",
    storageBucket: "workshop-dd355.appspot.com",
    messagingSenderId: "789105656501",
    appId: "1:789105656501:web:48f68acef70db9547bf4fc",
    measurementId: "G-9ERZE68G5M"
};
const firebase_app = initializeApp(firebaseConfig);
const db = getFirestore();


app.get('/', (req, res) => {
    res.send();
})

app.get('/users', async(req, res) => {
    const docRef = doc(db, "users", "3YF7wfRJ9RZphGRrR99a");
    const docSnap = await getDoc(docRef);
    if (docSnap.exists()) {
        res.send(docSnap.data());
    } else {
        // docSnap.data() will be undefined in this case
        console.log("No such document!");
    }
    await setDoc(doc(db, "users", "test"), {
        name: "Los Angeles",
        state: "CA",
        country: "USA"
    });
    docSnap = getDoc(docRef);
    if (docSnap.exists()) {
        res.send(docSnap.data());
    } else {
        // docSnap.data() will be undefined in this case
        console.log("No such document!");
    }
})

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})