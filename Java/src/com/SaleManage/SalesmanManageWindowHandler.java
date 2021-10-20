package com.SaleManage;

import com.SaleManage.Services.SalesmanService;
import com.SaleManage.Services.SalesmanServiceImpl;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SalesmanManageWindowHandler implements ActionListener {
    private SalesmanManageWindow salesmanManageWindow;

    public SalesmanManageWindowHandler(SalesmanManageWindow salesmanManageWindow) {
        this.salesmanManageWindow = salesmanManageWindow;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton jButton = (JButton) e.getSource();
        String text = jButton.getText();

        if ("添加".equals(text)) {
            new AddSalesmanWindow(salesmanManageWindow);
        } else if ("修改".equals(text)) {
            String[] selectedSalesmanNumbers = salesmanManageWindow.getSelectedSalesmanNumbers();

            if (selectedSalesmanNumbers.length != 1) {
                JOptionPane.showMessageDialog(salesmanManageWindow, "一次只能修改一行！");
                return;
            }

            new UpdateSalesmanWindow(salesmanManageWindow, selectedSalesmanNumbers[0]);
        } else if("删除".equals(text)) {
            String[] selectedSalesmanNumbers = salesmanManageWindow.getSelectedSalesmanNumbers();

            if (selectedSalesmanNumbers.length == 0) {
                JOptionPane.showMessageDialog(salesmanManageWindow,"请选择要删除的行！");
                return;
            }

            int option = JOptionPane.showConfirmDialog(salesmanManageWindow,"确定要删除选择的"+selectedSalesmanNumbers.length+"行吗？","确认删除",JOptionPane.YES_NO_OPTION);

            if (option == JOptionPane.YES_OPTION) {
                SalesmanService salesmanService = new SalesmanServiceImpl();
                boolean deleteResult = salesmanService.delete(selectedSalesmanNumbers);

                if (deleteResult) {
                    salesmanManageWindow.reloadTable();
                } else {
                    JOptionPane.showMessageDialog(salesmanManageWindow,"删除失败");
                }
            }
        } else if ("查询".equals(text)) {
            salesmanManageWindow.reloadTable();
        }
    }
}