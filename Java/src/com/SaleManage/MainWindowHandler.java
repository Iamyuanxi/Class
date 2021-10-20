package com.SaleManage;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainWindowHandler implements ActionListener {

    public MainWindowHandler(MainWindow mainWindow) {
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton jButton = (JButton) e.getSource();
        String text = jButton.getText();

        if ("产品管理".equals(text)) {
            new ProductManageWindow();
        } else if ("人员管理".equals(text)) {
            new SalesmanManageWindow("人员管理");
        }
    }
}
