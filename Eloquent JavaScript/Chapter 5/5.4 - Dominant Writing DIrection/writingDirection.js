/*
    Dominant writing direction

    Write a function that computes the dominant writing direction in a string of
    text. Remember that each script object has a direction property that can be
    "ltr" (left to right), "rtl" (right to left), or "ttb" (top to bottom).
    The dominant direction is the direction of a majority of the characters that
    have a script associated with them. The characterScript and countBy functions
    defined earlier in the chapter are probably useful here.
*/

function characterScript(code)
{
    for (let script of SCRIPTS)
    {
        if (script.ranges.some(([from, to]) => {
            return code >= from && code < to; }))
        {
            return script;
        }
    }
    return null;
}


function countBy(items, groupName)
{
    let counts = [];
    for (let item of items)
    {
        let name = groupName(item);
        let known = counts.findIndex(c => c.name == name);

        if (known == -1)
            counts.push({name, count: 1});
        else
            counts[known].count++;
    }
    return counts;
}

function dominantWritingDirection(text)
{
    let scripts = countBy(text, character => {
            let script = characterScript(character.codePointAt(0));
            return script ? script.direction : "none";
        }).filter(script => script.name != "none");

    if (scripts.length == 0)
        return "ltr";

    return scripts.reduce((a, b) => b.count > a.count ? b : a).name;
}