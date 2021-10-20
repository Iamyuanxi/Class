package com.SaleManage;

import com.SaleManage.Entity.Salesman;
import com.SaleManage.Services.SalesmanService;
import com.SaleManage.Services.SalesmanServiceImpl;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AddSalesmanWindowHandler implements ActionListener {
    private AddSalesmanWindow addSalesmanWindow;
    private SalesmanManageWindow salesmanManageWindow;

    public AddSalesmanWindowHandler(AddSalesmanWindow addSalesmanWindow, SalesmanManageWindow salesmanManageWindow) {
        this.addSalesmanWindow = addSalesmanWindow;
        this.salesmanManageWindow = salesmanManageWindow;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton jButton = (JButton) e.getSource();
        String text = jButton.getText();

        if ("添加".equals(text)) {
            SalesmanService salesmanService = new SalesmanServiceImpl();
            Salesman salesman = addSalesmanWindow.buildSalesman();

            boolean addResult = salesmanService.add(salesman);

            if (addResult) {
                salesmanManageWindow.reloadTable();
                addSalesmanWindow.dispose();
            } else {
                JOptionPane.showMessageDialog(addSalesmanWindow,"添加失败");
            }
        }
    }
}
