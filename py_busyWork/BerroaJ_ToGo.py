"""
Author name: Jason Berroa
Date: 2024/04/15
Program Name: BerroaJ_ToGo.py
Purpose: simulate a restaurant menu
"""


import tkinter as tk

class RestaurantApp(tk.Tk):
    # Class Init
    def __init__(self):
        super().__init__()
        self.title("Restaurant ToGo Menu")
        self.geometry("400x400")
        self.items = {
            "Bacon Cheeseburger" : 14,
            "Buffalo Chicken Sandwich" : 13,
            "Santa Fe Salad" : 12,
            "Chicken Wings" : 15,
            "Sweet Potato Fries" : 3.5,
            "Nachos" : 8,
            "Onion Rings" : 4.5
        }
        self.order = {}

        self.create_menu()
        self.create_order_summary()
        self.create_place_order_button()

    def create_menu(self):
        self.menu_frame = tk.Frame(self)
        self.menu_frame.pack(pady=10)

        # Menu Headline
        menu_headline = tk.Label(self.menu_frame, text="Menu", font=("Helvetica", 16, "bold"))
        menu_headline.grid(row=0, column=0, padx=10)

        # Quantity Headline
        quantity_headline = tk.Label(self.menu_frame, text="Quantity", font=("Helvetica", 16, "bold"))
        quantity_headline.grid(row=0, column=1, padx=10)

        # Menu Items and Entry Fields
        for i, (item, price) in enumerate(self.items.items(), start=1):
            menu_lbl = tk.Label(self.menu_frame, text=f"{item}: ${price}")
            menu_lbl.grid(row=i, column=0, padx=10, sticky="w")
            entry = tk.Entry(self.menu_frame)
            entry.grid(row=i, column=1, padx=10, sticky="e")
            self.order[item] = {"price": price, "entry": entry}

    def create_place_order_button(self):
        self.place_order_btn = tk.Button(self, text="Place Order", command=self.place_order)
        self.place_order_btn.pack(pady=10)

    def create_order_summary(self):
        self.order_summary = tk.Text(self, height=10, width=40)
        self.order_summary.pack()

    def place_order(self):
        self.order_summary.delete(1.0, tk.END)
        total_cost = 0
        self.order_summary.insert(tk.END, "Order Summary:\n\n")
        for item, info in self.order.items():
            quantity = info["entry"].get()
            if quantity.isdigit():
                quantity = int(quantity)
                if quantity > 0:
                    item_cost = quantity * info["price"]
                    total_cost += item_cost
                    self.order_summary.insert(tk.END, f"{item}: {quantity} x ${info['price']} = ${item_cost}\n")
        self.order_summary.insert(tk.END, f"\nTotal Cost: ${total_cost}")

if __name__ == "__main__":
    app = RestaurantApp()
    app.mainloop()






