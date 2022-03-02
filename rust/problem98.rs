fn read_words() -> std::io::Result<String> {
    use std::fs::File;
    use std::io::prelude::*;
    
    let mut file = File::open("p098_words.txt")?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)?;
    Ok(contents)
}

fn main() {
    let words = read_words();
    
}
