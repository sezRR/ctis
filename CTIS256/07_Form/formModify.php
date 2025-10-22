<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Web Form App</title>
</head>
<body>    
            <h1>Web Form App</h1>
            <form method="GET">
                <table>
                    <tr>
                        <td>Name:</td>
                        <td><input type="text" name="username" ></td>
                    </tr>
                    <tr>
                        <td>Password:</td>
                        <td><input type="password" name="pass"></td>
                    </tr>
                    <tr>
                        <td>Languages:</td>
                        <td>
                            <input type="checkbox" name="C" id="C" >
                            <label for="C">C</label>

                            <input type="checkbox" name="JS" id="JS" >
                            <label for="JS">JS</label>

                            <input type="checkbox" name="Java" id="Java" >
                            <label for="Java">Java</label>
                        </td>
                    </tr>
                    <tr>
                        <td>Fruits:</td>
                        <td>
                            <input type="checkbox" name="fruits[]" id="Cherry" value="Cherry">
                            <label for="Cherry">Cherry</label>

                            <input type="checkbox" name="fruits[]" id="Banana" value="Banana">
                            <label for="Banana">Banana</label>

                            <input type="checkbox" name="fruits[]" id="Apple" value="Apple">
                            <label for="Apple">Apple</label>
                        </td>
                    </tr>
                    <tr>
                        <td>Status:</td>
                        <td>
                            <input type="radio" name="status" id="undergrad" value="undergrad" >
                            <label for="undergrad">Undergrad</label>

                            <input type="radio" name="status" id="MSc" value="MSc">
                            <label for="MSc">MSc</label>

                            <input type="radio" name="status" id="PHD" value="PHD">
                            <label for="PHD">PHD</label>
                        </td>
                    </tr>
                    <tr>
                        <td>Cities:</td>
                        <td>
                        <select name="city" id="city" >
                            <option value="Ankara">Ankara</option>;
                            <option value="Istanbul">Istanbul</option>;
                            <option value="Izmir">Izmir</option>;                             
                            </select>
                        </td>
                    </tr>
                    <tr>
                        <td>Message:</td>
                        <td>
                            <textarea name="message" cols="30" rows="5"></textarea>
                        </td>
                    </tr>
                    <tr>
                        <td colspan="2">
                            <input type="submit" value="Send" name="btnSend">
                        </td>
                    </tr>
                </table>

            </form>
     
</body>
</html>