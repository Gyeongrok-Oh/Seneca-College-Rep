package com.example.myapplication;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Context;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class AdminHomeActivity extends AppCompatActivity {

    private RecyclerView recyclerView;
    private List<Customer> customerList;

    private CustomerAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_admin_home);

        recyclerView = findViewById(R.id.customerRecyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        customerList = new ArrayList<>();
        adapter = new CustomerAdapter(this, customerList);
        recyclerView.setAdapter(adapter);


        ItemTouchHelper itemTouchHelper = new ItemTouchHelper(simpleCallback);
        itemTouchHelper.attachToRecyclerView(recyclerView);


        loadCustomers();


        Button logoutButton = findViewById(R.id.logoutButton);
        logoutButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });
    }

    private void loadCustomers() {

        customerList.add(new Customer("John Doe", "1234567890", "New York", ProcessStatus.AWAITED));
        customerList.add(new Customer("Jane Smith", "0987654321", "Los Angeles", ProcessStatus.AWAITED));
        customerList.add(new Customer("Alice Johnson", "9876543210", "Chicago", ProcessStatus.AWAITED));

        recyclerView.getAdapter().notifyDataSetChanged();
    }


    ItemTouchHelper.SimpleCallback simpleCallback = new ItemTouchHelper.SimpleCallback(0, ItemTouchHelper.LEFT | ItemTouchHelper.RIGHT) {
        @Override
        public boolean onMove(@NonNull RecyclerView recyclerView, @NonNull RecyclerView.ViewHolder viewHolder, @NonNull RecyclerView.ViewHolder target) {
            return false;
        }

        @Override
        public void onSwiped(@NonNull RecyclerView.ViewHolder viewHolder, int direction) {
            final int position = viewHolder.getAdapterPosition();
            final Customer deletedCustomer = customerList.get(position);


            new AlertDialog.Builder(AdminHomeActivity.this)
                    .setTitle("Confirm Deletion")
                    .setMessage("Are you sure you want to delete this customer?")
                    .setPositiveButton(android.R.string.yes, (dialog, which) -> {

                        customerList.remove(position);

                        recyclerView.getAdapter().notifyItemRemoved(position);

                        Toast.makeText(AdminHomeActivity.this, "Customer deleted", Toast.LENGTH_SHORT).show();

                        deleteCustomerFromRoomDB(deletedCustomer);
                    })
                    .setNegativeButton(android.R.string.no, (dialog, which) -> {

                        recyclerView.getAdapter().notifyItemChanged(position);
                    })
                    .show();
        }
    };

    public static void deleteCustomerFromRoomDB(Customer customer) {

        // Implement this method to delete customer from RoomDB

    }

    public static class CustomerAdapter extends RecyclerView.Adapter<CustomerAdapter.CustomerViewHolder> {

        private final List<Customer> customerList;
        private final Context context;

        public CustomerAdapter(Context context, List<Customer> customerList) {
            this.context = context;
            this.customerList = customerList;
        }

        @NonNull
        @Override
        public CustomerViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_customer, parent, false);
            return new CustomerViewHolder(view, context, customerList);
        }

        @Override
        public void onBindViewHolder(@NonNull CustomerViewHolder holder, int position) {
            Customer customer = customerList.get(position);
            holder.bind(customer);
        }

        @Override
        public int getItemCount() {
            return customerList.size();
        }

        public class CustomerViewHolder extends RecyclerView.ViewHolder {

            private final TextView nameTextView;
            private final TextView phoneTextView;
            private final TextView cityTextView;
            private final TextView statusTextView;
            private final Context context;
            private final List<Customer> customerList;

            public CustomerViewHolder(View itemView, Context context, List<Customer> customerList) {
                super(itemView);
                this.context = context;
                this.customerList = customerList;
                nameTextView = itemView.findViewById(R.id.nameTextView);
                phoneTextView = itemView.findViewById(R.id.phoneTextView);
                cityTextView = itemView.findViewById(R.id.cityTextView);
                statusTextView = itemView.findViewById(R.id.statusTextView);
            }

            public void bind(Customer customer) {
                nameTextView.setText(customer.getName());
                phoneTextView.setText(customer.getPhone());
                cityTextView.setText(customer.getCity());
                statusTextView.setText(customer.getProcessStatus().toString());

                // Set background color based on process status
                int backgroundColor = getBackgroundColor(customer.getProcessStatus());
                itemView.setBackgroundColor(backgroundColor);
            }

            private int getBackgroundColor(ProcessStatus status) {
                switch (status) {
                    case AWAITED:
                        return ContextCompat.getColor(context, R.color.yellow);
                    case FAILEDTOREACH:
                        return ContextCompat.getColor(context, R.color.light_red);
                    case ONBOARDED:
                        return ContextCompat.getColor(context, R.color.light_green);
                    case INPROCESS:
                        return ContextCompat.getColor(context, R.color.mid_green);
                    case COMPLETED:
                        return ContextCompat.getColor(context, R.color.dark_green);
                    case DENIED:
                        return ContextCompat.getColor(context, R.color.red);
                    default:
                        return ContextCompat.getColor(context, android.R.color.white);
                }
            }
        }

    }
}

