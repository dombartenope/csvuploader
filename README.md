# CSV Uploader
### The idea from this was formed due to the constant requests for a csv uploader for users rather than just an uploader that can update existing users

- *This project works by taking in data written into an input csv file, it then parses each column (defined by comma delimiters) and adds to a user object that will then used to populate the parameters within a cURL request to the OneSignal Add A Device api.*

### This will be updated to work with the user model upon it's official release as this API will be changing
---
## To use:
1. Add your user data into the second row of the CSV
- Anything that you would like to leave blank should just be left as a comma (e.g. dom,29,,OneSignal)
2. From the terminal run `./main` and ensure that your data is printing out successfully 
3. TODO: running should make a request to the api using libcurl within the main.cpp