package com.SaleManage;

import com.SaleManage.Entity.Salesman;
import com.SaleManage.Services.SalesmanService;
import com.SaleManage.Services.SalesmanServiceImpl;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class UpdateSalesmanWindowHandler implements ActionListener {
    private UpdateSalesmanWindow updateSalesmanWindow;
    private SalesmanManageWindow salesmanManageWindow;

    public UpdateSalesmanWindowHandler(UpdateSalesmanWindow updateSalesmanWindow, SalesmanManageWindow salesmanManageWindow) {
        this.updateSalesmanWindow = updateSalesmanWindow;
        this.salesmanManageWindow = salesmanManageWindow;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton jButton = (JButton) e.getSource();
        String text = jButton.getText();

        if ("修改".equals(text)) {
            SalesmanService salesmanService = new SalesmanServiceImpl();
            Salesman salesman = updateSalesmanWindow.buildUpdateSalesman();
            boolean updateResult = salesmanService.update(salesman);

            if (updateResult) {
                //重新加载表格查到最新数据
                salesmanManageWindow.reloadTable();
                updateSalesmanWindow.dispose();
            } else {
                JOptionPane.showMessageDialog(updateSalesmanWindow,"修改失败");
            }
        }
    }
}
