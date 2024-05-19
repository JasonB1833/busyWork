import requests
from bs4 import BeautifulSoup
import random

def get_baby_names(url, start_row, end_row):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')

    names = []
    
    for row in soup.select('table.wikitable tr')[start_row : end_row]:  # Skip header row
        columns = row.find_all('td')
        if columns:
            name = columns[1].text.strip()
            names.append(name)

    return names

def main():
    wikipedia_url = 'https://en.wikipedia.org/wiki/List_of_most_popular_given_names'
    
     # Get user input for the region
    region = input("Enter the region (e.g., Africa, Asia, Europe): ").lower()


    # Define the rows corresponding to each region
    region_rows = {
        'africa': (1, 20),
        'asia': (20, 40),
        'europe': (40, 60),
        # Add more regions as needed
    }


    if region in region_rows:
            start_row, end_row = region_rows[region]
            baby_names = get_baby_names(wikipedia_url, start_row, end_row)



    random_names = random.sample(baby_names, min(10, len(baby_names)))
    print(', '.join(random_names))
    #for name in baby_names:
     #   print(name)

if __name__ == "__main__":
    main()
