/*
    Deep comparison

    The == operator compares objects by identity. But sometimes you’d prefer to
    compare the values of their actual properties.
        Write a function deepEqual that takes two values and returns true only if they
    are the same value or are objects with the same properties, where the values
    of the properties are equal when compared with a recursive call to deepEqual.
        To find out whether values should be compared directly (use the === operator
    for that) or have their properties compared, you can use the typeof operator.
    If it produces "object" for both values, you should do a deep comparison.
    But you have to take one silly exception into account: because of a historical
    accident, typeof null also produces "object".
        The Object.keys function will be useful when you need to go over the properties
    of objects to compare them.
*/

function deepEqual(value1, value2)
{
    if (typeof value1 === "object" && typeof value2 === "object")
    {
        // Check if one or both values are equal to null
        if (value1 === null || value2 === null)
        {
            if (value1 === null && value2 === null)
                return true;
            else
                return false;
        }
        
        let objectProperties = Object.keys(value1);
        if (objectProperties.length < Object.keys(value2))
            objectProperties = Object.keys(value2);

        // objectProperties will now bind an array of the property names of the object with the most properties

        for (let property of objectProperties)
        {
            if (!deepEqual(value1[property], value2[property]))
                return false;
        }

        return true;
    }
    else
        return value1 === value2;
}

window.onload = function()
{
    let object1 = {
        number: 5,
        string: "Tracer"
    };
    let object2 = {
        number: 5,
        string: "Kurisu"
    };
    let object3 = {
        number: 10,
        string: "Okabe"
    };
    let object4 = {
        number: 5,
        string: "Kurisu"
    };
    let object5 = {
        string: "Kurisu",
        number: 5
    };

    /*
        During testing of the function deepEqual, number1 and number3 should return true.
        string2 and string 3 should return true.
        object2 and object4 should return true.
        Everything else should return false.
    */

    console.log(deepEqual(1, 5));
    console.log(deepEqual(2, 2));
    console.log(deepEqual("hello", "world"));
    console.log(deepEqual("hello", "hello"));
    console.log(deepEqual(3, "3"));
    console.log(deepEqual(object1, object2));
    console.log(deepEqual(object3, object4));
    console.log(deepEqual(object2, object4));
    console.log(deepEqual(object2, object5));
}